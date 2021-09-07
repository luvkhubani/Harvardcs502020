-- Keep a log of any SQL queries you execute as you solve the mystery.
-- name of tables   airports      crime_scene_reports     people      atm_transactions    flights    phone_calls     bank_accounts    interviews
-- courthouse_security_logs     passengers
SELECT description FROM crime_scene_reports WHERE day = 28 AND month = '7' AND street = 'Chamberlin Street';
-- TO FIND THE DESCRIPTION OF CRIMES ON THAT DAY AND TIME.
-- O/P Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
--Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.

-- TO CHECK FOR THREE INTERVIEWEES ID ,NAME AND TRANSCRIPT ON 28/07/2020
SELECT id, transcript , name FROM interviews WHERE transcript LIKE '%courthouse%' AND day = 28 AND month = '7';

 -- initially checked for all the activities on that particular date
SELECT id , activity , license_plate FROM courthouse_security_logs WHERE day = 28 AND month = '7';

-- now checking data with time.
SELECT id , activity , license_plate , hour , minute FROM courthouse_security_logs WHERE day = 28 AND month = '7';

-- now checking the names AND DATA of the people who left the place using the license plate.
SELECT people.license_plate , people.id , people.name , people.phone_number , people.passport_number FROM people JOIN courthouse_security_logs ON
people.license_plate = courthouse_security_logs.LICENSE_PLATE WHERE day = 28 AND month = '7' AND hour = 10 AND minute > 15 AND minute < 25;

-- Now as we got the name we wiil fetch data from interveiw 2 , DATA FROM LEAD 162 ATM TRANSACTIONS ON EUGENE STREET
SELECT * FROM atm_transactions WHERE day = 28 AND month = '7' AND atm_location = 'Fifer Street' AND transaction_type = 'withdraw';

-- Now from This data we will check the suspected people with their balance
SELECT people.name , bank_accounts.account_number , bank_accounts.creation_year FROM people
JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.LICENSE_PLATE
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE day = 28 AND month = '7' AND hour = 10 AND minute > 15 AND minute < 25;

-- Now as we have checked for the persons who left the town does have available account or not, and also have checked that whom from the available
-- account have withdrawn the amt.
SELECT people.name , bank_accounts.account_number , bank_accounts.creation_year FROM people
JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.LICENSE_PLATE
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE atm_transactions.day = 28 AND atm_transactions.month = '7' AND courthouse_security_logs.hour = 10 AND
courthouse_security_logs.minute > 15 AND courthouse_security_logs.minute < 25 AND atm_transactions.atm_location = 'Fifer Street'
AND atm_transactions.transaction_type = 'withdraw' ;

-- the list left with suspicion of theft is Ernest , Russell , Elizabeth and Danielle.
-- NOW CHECKING FOR INTERVIW 3 LEAD 163.

-- Now checking for all the phone calls happened at that day for less than a minute.

SELECT * FROM phone_calls WHERE month = 7 AND year = 2020 AND duration > 0 AND duration < 60;

-- NOW AS WE HAVE RECEIVED THE LIST OF PEOPLE WHO ALL HAVE CALLED FOR LESS THAN A MINUTE NOW WE WILL CHECK FOR THE ONES WHO ARE IN SUSPICION OF THEFT .

SELECT people.name , phone_calls.caller , phone_calls.receiver , phone_calls.duration FROM people
JOIN courthouse_security_logs ON people.license_plate = courthouse_security_logs.LICENSE_PLATE
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE atm_transactions.day = 28 AND atm_transactions.month = '7' AND courthouse_security_logs.hour = 10 AND
courthouse_security_logs.minute > 15 AND courthouse_security_logs.minute < 25 AND atm_transactions.atm_location = 'Fifer Street'
AND atm_transactions.transaction_type = 'withdraw' AND phone_calls.duration > 0 AND phone_calls.duration < 60;

-- Here we are checking that the data we have fethched till date is perfect that, the name and their correspodings mobile no. are same or not.
-- now thw suspicion of theft is left on earnest and russel.
-- name | caller | receiver | duration
-- Ernest | (367) 555-5533 | (375) 555-8161 | 45
-- Ernest | (367) 555-5533 | (455) 555-5315 | 31
-- Russell | (770) 555-1861 | (725) 555-3243 | 49
SELECT * FROM PEOPLE ORDER BY 2;

-- now we are checking for the ones who have received the calls manuaaly
-- Ernest called for 45 seconds
SELECT name FROM people WHERE phone_number = '(375) 555-8161'; -- this is Berthold.
-- Ernest called for 31 seconds
SELECT name FROM people WHERE phone_number = '(455) 555-5315'; -- this is Charlotte.
 -- now Russel called for 49 seconds
SELECT name FROM people WHERE phone_number = '(725) 555-3243'; -- this is Philip.

-- SUSPICION OF ACCOMPLICE ARE Philip , Charlotte , Berthold.

-- Here we have checked the name of all the airports.
SELECT * FROM airports;
-- OUTPUT
-- id | abbreviation | full_name | city
-- 1 | ORD | O'Hare International Airport | Chicago
-- 2 | PEK | Beijing Capital International Airport | Beijing
-- 3 | LAX | Los Angeles International Airport | Los Angeles
-- 4 | LHR | Heathrow Airport | London
-- 5 | DFS | Dallas/Fort Worth International Airport | Dallas
-- 6 | BOS | Logan International Airport | Boston
-- 7 | DXB | Dubai International Airport | Dubai
-- 8 | CSF | Fiftyville Regional Airport | Fiftyville
-- 9 | HND | Tokyo International Airport | Tokyo
-- 10 | CDG | Charles de Gaulle Airport | Paris
-- 11 | SFO | San Francisco International Airport | San Francisco
-- 12 | DEL | Indira Gandhi International Airport | Delhi

-- NOW WE WILL CHECK FOR THE FLIGHTS WHICH WERE TAKEN ON 29/07/2020 FROM fiftyville.
SELECT * FROM flights WHERE YEAR = 2020 AND month = 7 AND DAY = 29;
-- FRO THIS DATA WE GOT TO KNOW THAT THE EARLIEST FLIGHT FROM FIFTYVILLE ON 29/07/2020 WAS AT 8:20 AND IT HAD BEEN TO LONDON AIRPORT NO. 4
-- id | origin_airport_id | destination_airport_id | year | month | day | hour | minute
-- 18 | 8 | 6 | 2020 | 7 | 29 | 16 | 0
-- 23 | 8 | 11 | 2020 | 7 | 29 | 12 | 15
-- 36 | 8 | 4 | 2020 | 7 | 29 | 8 | 20 THIS ON $$
-- 43 | 8 | 1 | 2020 | 7 | 29 | 9 | 30
-- 53 | 8 | 9 | 2020 | 7 | 29 | 15 | 20

-- NOW WE WILL CHECK FOR THE ONES WHO HAVE GONE ON THAT FLIGHT.
SELECT people.name FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
WHERE flight_id = 36;
-- output
-- name
-- Doris
-- Roger
-- Ernest HERE WE HAVE GOT OUR STAR HE IS THE THIEF
-- Edward
-- Evelyn
-- Madison
-- Bobby
-- Danielle

