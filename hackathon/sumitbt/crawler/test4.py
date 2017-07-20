import urllib2
import MySQLdb
import re
from bs4 import BeautifulSoup
import sys
reload(sys)  
sys.setdefaultencoding('utf8')
db = MySQLdb.connect(host="localhost",user="root",passwd="10001011",db="hackathon")
cur = db.cursor()
cur.execute("SELECT * FROM query")
keys = cur.fetchall()
d = {'Jan':'01','Feb':'02','Mar':'03','Apr':'04','May':'05','Jun':'06','Jul':'07','Aug':'08','Sep':'09','Oct':'10','Nov':'11','Dec':'12'}
if(len(keys)>0):
	base = 'https://www.youtube.com/results?search_query='
	for key in keys:
		#print key[3]
		if(key[3]=="False"):
			try:
				id = key[0]
				cur.execute("UPDATE `hackathon`.`query` SET `scrapped`='True' WHERE `key_id`='"+str(id)+"';")
				db.commit()
				fieldId = key[2]
				typea = key[4]
				#print fieldId
				#print typea
				url = base + key[1] + "+biotechnology"
				#print url
				page = urllib2.urlopen(url)
				soup = BeautifulSoup(page, "lxml")
				s = soup.find_all('div',class_='yt-lockup-dismissable yt-uix-tile')
				preview = r"^https://i.ytimg.com/vi/(.)+"
				url = r"^/watch\?v=(.)+"
				for k in s:
					s1 = str(k.contents[0])
					c = s1.split('"')
					do = 0
					u=" "
					for i in c:
						if(do==1):
							t = i[1:5]
							#print i[1:5]
							do = 0
						if re.match(url,i):
							u = i
							#print i
						if re.match(preview,i):
							p = i
							#print i
						if(i=="video-time"):
							do = 1
					if(len(u)>20):
						continue
					page2 = urllib2.urlopen("https://www.youtube.com"+u)
					soup2 = BeautifulSoup(page2, 'html.parser')
					ttl = soup2.find("span",class_="watch-title").contents[0]
					title = ttl.strip().encode('utf-8').replace("'","")
					#print title
					temp = soup2.find("p",id="eow-description")
					temp2 = re.sub(r'<.*?>',' ',str(temp))
					desc = temp2.strip().encode('utf-8').replace("'","")
					#print desc
					listg = soup2.findAll("a",class_="g-hovercard yt-uix-sessionlink      spf-link ")
					genre = listg[1].contents[0]
					#print genre
					if(genre != "Science & Technology" and genre != "People & Blogs" and genre != "Education"):
						continue
					s = soup2.find_all('strong',class_='watch-time-text')
					v1 = s[0].contents[0]
					v2 = v1[13:].encode('utf-8').replace(",","").split()
					date = v2[2]+"-"+d[v2[0]]+"-"+v2[1]
					#print date
					sql = """INSERT INTO `hackathon`.`video` (`url`, `preview`, `title`, `length`, `description`, `field_id`, `key_id`, `type`, `date`) VALUES ('"""+u+"""', '"""+p+"""','"""+title+"""','"""+t+"""','"""+desc+"""','"""+str(fieldId)+"""','"""+str(id)+"""','"""+typea+"""','"""+date+"""');"""
					#print sql
					cur.execute(sql)
					db.commit()
			except Exception as e:
				print e
db.close()
