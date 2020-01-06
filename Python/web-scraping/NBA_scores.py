from bs4 import BeautifulSoup
import sys
import requests
import datetime

# Input a user string until they enter a valid format
while True:
	# Input date to find scores from. Gives the option of doing previous day's scores or any date the user wishes to enter
	curdate = input("Enter the date you want the score in YYYYMMDD or say 'yesterday': ")

	if curdate == "yesterday":
		yesterday = datetime.date.today() - datetime.timedelta(days=1)
		curdate = yesterday.strftime('%Y%m%d')
		break
	else:
		try:
			int(curdate)
			break
		except:
			print("Not a valid date format")

# Input the link and convert into BeautifulSoup format
link = requests.get("https://www.cbssports.com/nba/scoreboard/" + curdate + "/")
link_list = link.text
soup = BeautifulSoup(link_list, 'html.parser')

# Create a list containing all team names from the given date
teams = []
x = soup.find_all("a", class_="team")
for i, link in enumerate(x):
    teams.append([link.contents[0]])

   
# Create lists for storing scores as well as if the game went into overtime
scores = []
overtime = []
b = soup.find_all("td")


for link in b:
	# Reset the score and quarters if the information does not contain a number
    if link.contents[0] == "\n":
        score = 0
        quarters = 0
    else:
		# Check if a game went into overtime by summing up each quarter score until it equals the final score
        if score == int(link.contents[0]):
            scores.append(score)
            if quarters == 5:
                overtime.append("OT")
            else:
                overtime.append("Final")
                
		# Sum up the score of each quarter
        score += int(link.contents[0])
		# Iterate the quarters to track overtimes
        quarters += 1
        
# Concatenate scores with their respective teams
for i in enumerate(teams):
    teams[i[0]].append(scores[i[0]])

# Print the date the user requested
print("NBA scores for the date of " + datetime.datetime.strptime(curdate, "%Y%m%d").strftime("%B %d, %Y") + ":")

# If there is not data for the provided date, let the user know
if teams == []:
	print("It appears there were no NBA games on the given date. Check your input format and try again.")
 
# Print off each game and its score
for i in range(0, len(teams), 2):
    print(teams[i][0] + " vs. " + teams[i+1][0] + ", " + overtime[i])
    print("    " + teams[i][0] + ": " + str(teams[i][1]))
    print("    " + teams[i+1][0] + ": " + str(teams[i+1][1]))
