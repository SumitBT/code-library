import webbrowser
import time
i=0
print("started!")
while(i<3):
    time.sleep(10)
    webbrowser.open("youtube.com")
    i=i+1
print("ended!")
