import eyed3
import os
from lyricsgenius import Genius
genius = Genius("") #you should put your genius token there
a = os.listdir()
c = 0
for item in a:
    try:
       audio = eyed3.load(item)
       busq = genius.search_song(audio.tag.title, audio.tag.artist)
       try:
           audio.tag.comments.set(busq.lyrics)
           audio.tag.lyrics.set(busq.lyrics)
           audio.tag.save()
       except:
           pass
    except:
       pass
    c = c+1   
    print( c / len(a))  


