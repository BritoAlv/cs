import os
import eyed3
import shutil
a = os.listdir("./Year?/")
for item in a:
    try:
        audio = eyed3.load("./Year?/" + item)
        year = audio.tag.recording_date.year
        if year <= 1969:
           shutil.move("./Year?/" + item, "./1957 - 1969/"+ item)
        elif year <= 1979:
           shutil.move("./Year?/" + item, "./1970 - 1979/"+ item)
        elif year <= 1989:
           shutil.move("./Year?/" + item, "./1980 - 1989/"+ item) 
        elif year <= 1999:
           shutil.move("./Year?/" + item, "./1990 - 1999/"+ item)
        else:
           shutil.move("./Year?/" + item, "./"+ str(year)+ "/"+ item)                                     
    except:
        pass    

