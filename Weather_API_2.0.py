# Description: Extracting weather details of multiple cities using API and printing them using json formatting

import requests
import json

data = {}


def getWeatherForecast(city, days=1, aqi="no", alerts="no"):
    response = requests.get(
        "http://api.weatherapi.com/v1/forecast.json?key=f0593318d7224913aad153309220404&q=" + city + "&days=" + str(
            days) + "&aqi=" + aqi + "&alerts=" + alerts)
    responseJson = response.json()
    return responseJson


def scrapeData(city):
    city = city.title()
    forecastData = getWeatherForecast(city)
    try:
        maxtemp_f = forecastData["forecast"]["forecastday"][0]["day"]["maxtemp_f"]
        mintemp_f = forecastData["forecast"]["forecastday"][0]["day"]["mintemp_f"]
        avghumidity = forecastData["forecast"]["forecastday"][0]["day"]["avghumidity"]
        maxwind_mph = forecastData["forecast"]["forecastday"][0]["day"]["maxwind_mph"]
        daily_chance_of_rain = forecastData["forecast"]["forecastday"][0]["day"]["daily_chance_of_rain"]
        daily_chance_of_snow = forecastData["forecast"]["forecastday"][0]["day"]["daily_chance_of_snow"]
        percipitation = daily_chance_of_rain if daily_chance_of_rain > daily_chance_of_snow else daily_chance_of_snow
        condition = forecastData["current"]["condition"]["text"]

        data[city] = {"maxtemp_f": maxtemp_f, "mintemp_f": mintemp_f, "avghumidity": avghumidity,
                      "maxwind_mph": maxwind_mph, "percipitation": percipitation, "condition": condition}
        print("Saved, data retrieved!")
    except:
        print("Not saved, bad city request!")


def printData(data, item):
    print("I do have information about the weather in " + item+":")
    print(f"The high temperature is {data[item]['maxtemp_f']} degrees Fahrenheit.")
    print(f"The low temperature is {data[item]['mintemp_f']} degrees Fahrenheit.")
    print(f"The humidity is {data[item]['avghumidity']}%.")
    print(f"The wind speed is {data[item]['maxwind_mph']} mph.")
    print(f"The chance of precipitation is {data[item]['percipitation']}.0%.")
    print(f"{data[item]['condition']}.")
    print("---")


def getData(city):
    if city.lower() == "exit":
        print("Goodbye!")
        exit()
    elif city in data.keys():
        printData(data=data, item=city)
    elif city == "All":
        for i in data.keys():
            printData(data=data, item=i)
    elif city not in data.keys():
        print("I do not have information about the weather in " + city + ".\n---")

def start():
    print("---")
    while True:
        city = input("For what city would you like weather information? ").title()
        getData(city)

def inp():
    print("Hi there! Welcome to free weather reports with no ads!\n---")
    while True:
        city = input("Input weather data: ")
        city = city.title()
        if city.lower() == "end":
            start()
        elif city in data.keys():
            print("Sorry, that city is already entered!")
        else:
            scrapeData(city)

def main():
    inp()

if __name__ == "__main__":
    main()