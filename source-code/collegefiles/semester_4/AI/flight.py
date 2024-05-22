import pandas as pd

class Flight:
    def __init__(self, flightNumber, departure, arrival, maintenance):
        self.flightNumber = flightNumber
        self.departure = departure
        self.arrival = arrival
        self.maintenance = maintenance


def ConvertToMinutes(time):
    hours, minutes = map(int, time.split(':'))
    return hours * 60 + minutes


def ScheduleFlights(flights):
    flights.sort(key=lambda x: x.arrival)
    schedule = []
    overlap = []
    current_time = 0
    for flight in flights:
        departure = ConvertToMinutes(flight.departure)
        arrival = ConvertToMinutes(flight.arrival)
        maintenance = flight.maintenance
        if departure >= current_time + flight.maintenance:
            schedule.append(flight)
            current_time = arrival
        else:
            overlap.append(flight)
    return schedule, overlap

flights = [
    Flight("flight1", "08:00", "10:30", 30),
    Flight("flight2", "11:00", "13:30", 45),
    Flight("flight3", "14:00", "16:30", 20),
    Flight("flight4", "17:00", "19:30", 35),
    Flight("flight5", "20:00", "22:30", 25)
]

scheduledFlights, overlapedFlights = ScheduleFlights(flights)

columns=['Flight Number', 'Departure Time', 'Arrival Time', 'Maintenance Time']

flights_df = pd.DataFrame([(flight.flightNumber, flight.departure, flight.arrival, flight.maintenance) for flight in scheduledFlights],columns=columns)

overlapedflights_df = pd.DataFrame([(flight.flightNumber, flight.departure, flight.arrival, flight.maintenance) for flight in overlapedFlights],columns=columns)


print("\nScheduled Flights:")
print(flights_df)

print("\nDelayed Flights due to overlap:")
print(overlapedflights_df)