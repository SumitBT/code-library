import os
def myfunction():
    files=os.listdir(r"F:\Udacity\Python\prank")
    path=os.getcwd()
    os.chdir(r"F:\Udacity\Python\prank")
    for file in files:
        os.rename(file,file.translate(None,"0123456789"))
    os.chdir(path)
    print(files)
myfunction()
