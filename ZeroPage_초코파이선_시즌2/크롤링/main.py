import requests
import json
from bs4 import BeautifulSoup

response=requests.get("https://stats.tanks.gg/api/ranges/asia/Vulcan_SM")
#print(response.text)
json_data=json.loads(response.text)
#username_info=json_data["name"]
rating_overall=json_data["overall"]
rating_battles=json_data["battles"]
rating_intervals=json_data["intervals"]
#print(username_info)
#오버롤 전적 출력
print(rating_overall)
#100, 500, 1000배틀 전적 출력
print(rating_battles["100"])
print(rating_battles["500"])
print(rating_battles["1000"])
#1, 7, 30, 60일 기준 전적 출력
print(rating_intervals["1"])
print(rating_intervals["7"])
print(rating_intervals["30"])
print(rating_intervals["60"])