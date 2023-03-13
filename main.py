from requests_html import HTMLSession

with open("city.csv",'r') as f:
    city = f.read()
    #f.flush()
    f.close()
try: 
    s = HTMLSession()
    url = s.get(f"https://www.google.com/search?q=temperature+in+{city}")

    f = open("city.csv",'w')
    div = url.html.find("span#wob_tm")
    for i in div:
        tm = "Temperature: "+i.text+"°C\n"
        f.write(tm)

    prep = url.html.find("span#wob_pp")
    for i in prep:
        te = "Precepitation: "+i.text+"\n"
        f.write(te)
    hum = url.html.find("span#wob_hm")
    for i in hum:
        pe = "Humidity: "+i.text+"\n"
        f.write(pe)
    wind = url.html.find("span#wob_ws")
    for i in wind:
        ws = "wind: "+i.text+"\n"
        f.write(ws)
    f.close()
except:
    f = open("city.csv",'w')
    f.write("network error!")
    f.close()

