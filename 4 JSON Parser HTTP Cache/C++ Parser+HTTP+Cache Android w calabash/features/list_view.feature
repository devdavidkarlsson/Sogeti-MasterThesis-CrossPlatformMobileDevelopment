Feature: Running a test to ensure presence of parsed labels 
  As an iOS user with internet connection
  I want to see a table populated with capital cities
  So I can verify the JSON parser's function


Scenario: Presence
  Given the app is running
  Then I scroll to cell with "Kabul" label 
  Then I scroll to cell with "Tirana" label 
  Then I scroll to cell with "Algiers" label 
  Then I scroll to cell with "Pago pago" label 
  Then I scroll to cell with "Andorra la vella" label 
  Then I scroll to cell with "Luanda" label 
  Then I scroll to cell with "The valley" label 
  Then I scroll to cell with "St. John\'s" label 
  Then I scroll to cell with "Buenos Aires" label 
  Then I scroll to cell with "Yerevan" label 
  Then I scroll to cell with "Oranjestad" label 
  Then I scroll to cell with "Canberra" label 
  Then I scroll to cell with "Vienna" label 
  Then I scroll to cell with "Baku" label 
  Then I scroll to cell with "Nassau" label 
  Then I scroll to cell with "Manama" label 
  Then I scroll to cell with "Dhaka" label
