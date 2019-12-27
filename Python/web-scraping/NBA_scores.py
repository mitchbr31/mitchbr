from bs4 import BeautifulSoup
import requests
from datetime import date, timedelta

curdate = input("Enter the date you want the score in YYYYMMDD or say 'yesterday': ")

if curdate == "yesterday":
	yesterday = date.today() - timedelta(days=1)
	curdate = yesterday.strftime('%Y%m%d')

link = requests.get("https://www.cbssports.com/nba/scoreboard/" + curdate + "/")
link_list = link.text
soup = BeautifulSoup(link_list, 'html.parser')

teams = []
x = soup.find_all("a", class_="team")
for i, link in enumerate(x):
    teams.append([link.contents[0]])
    
scores = []
overtime = []
b = soup.find_all("td")

for link in b:
    if link.contents[0] == "\n":
        score = 0
        quarters = 0
    else:
        if score == int(link.contents[0]):
            scores.append(score)
            if quarters == 5:
                overtime.append("OT")
            else:
                overtime.append("Final")
                
        score += int(link.contents[0])
        quarters += 1
        
for i in enumerate(teams):
    teams[i[0]].append(scores[i[0]])

for i in range(0, len(teams), 2):
    print(teams[i][0] + " vs. " + teams[i+1][0] + ", " + overtime[i])
    print("    " + teams[i][0] + ": " + str(teams[i][1]))
    print("    " + teams[i+1][0] + ": " + str(teams[i+1][1]))
