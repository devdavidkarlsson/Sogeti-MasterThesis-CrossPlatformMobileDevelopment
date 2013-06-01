Feature: Running a test
  As an Android user with internet connection
  I want to test the Net, Cache and Parser classes
  So I can verify the parsing of cached and HTTP function

Scenario: Cache Verification
  Given the app is running
  Then I select "Refresh" from the menu
  Then I should see "Kabul"
  Then I touch the "Kabul" text
  Then I go back
  Then I select "Flush" from the menu
  Then I wait for 1 second
  Then I select "Refresh" from the menu
  Then I wait for 1 second
  Then I should see "Using HTTP"
  Then I scroll to cell with "Dhaka" label
  Then I touch the "Dhaka" text
  Then I wait for 1 second
  Then I should see "106 Dhaka"
  And I see "Latitude:23.72 Longitude:90.41"
  Then I go back
  Then I wait for 5 seconds
  Then I select "Refresh" from the menu
  Then I wait for 1 second
  Then I should see "Using HTTP"
  Then I select "Refresh" from the menu
  Then I should see "Using Cached"
  Then I select "Save" from the menu
  And take picture


