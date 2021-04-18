# Description: The program inputs the weather details of certain cities and then provides the given information as per the user's prompts

weather = []
curr = input("Input weather data: ").lower()
weather.append(curr)

if weather[0] != "end":
    print("Saved!")


while weather[-1] != "end":
    curr = input("Input weather data: ").lower()
    weather.append(curr)
    if weather[-1] != "end":
        print("Saved!")

city = []
currentTemperature = []
dayLow = []
dayHigh = []
humidity = []
pressure = []
visibility = []
windSpeed = []
windDirection = []
conditionDescription = []
for i in range(len(weather)-1):
    temp = weather[i].split('|')
    city.append(temp[0])
    currentTemperature.append(temp[1])
    dayLow.append(temp[2])
    dayHigh.append(temp[3])
    humidity.append(temp[4])
    pressure.append(temp[5])
    visibility.append(temp[6])
    windSpeed.append(temp[7])
    windDirection.append(temp[8])
    conditionDescription.append(temp[9])
currCity = input("For what city would you like weather information?").lower()
while currCity != 'exit':
    if currCity == "all":
        for i in range(len(weather) - 1):
            print("I do have information about the weather in", city[i].title())
            print("The high temperature is", dayHigh[i], "degrees Fargenheit.")
            print("The low temperature is", dayLow[i], "degrees Fargenheit.")
            print("The humidity is", humidity[i], "%.")
            print("The pressure is", pressure[i], "inHg.")
            print("The visibility is", visibility[i], "miles.")
            print("The wind speed is", windSpeed[i], "mph.")
            print("The wind direction is", windDirection[i], "degrees.")
            print("It is", conditionDescription[i], ".")
    elif currCity in city:
        currIndex = city.index(currCity)
        print("I do have information about the weather in", city[currIndex].title())
        print("The high temperature is", dayHigh[currIndex], "degrees Farhenheit.")
        print("The low temperature is", dayLow[currIndex], "degrees Farhenheit.")
        print("The humidity is", humidity[currIndex], "%.")
        print("The pressure is", pressure[currIndex], "inHg.")
        print("The visibility is", visibility[currIndex], "miles.")
        print("The wind speed is", windSpeed[currIndex], "mph.")
        print("The wind direction is", windDirection[currIndex], "degrees.")
        print("It is", conditionDescription[currIndex], ".")
    elif currCity not in city:
        print("I do not have information about the weather in", currCity)
    currCity = input("For what city would you like weather information?").lower()
print("Goodbye!")

