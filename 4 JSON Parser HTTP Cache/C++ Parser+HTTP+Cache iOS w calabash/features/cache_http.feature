Feature: Running a test
  As an iOS user with internet connection
  I want to test the Net, Cache and Parser classes
  So I can verify the parsing of cached and HTTP function

Scenario: Cache Verification
  Given the app is running
  Then I press "Refresh"
  Then I should see "Kabul"
  Then I press "Kabul"
  Then I press "OK"
  Then I press "Trash"
  Then I wait for 1 second
  Then I press "Refresh"
  Then I wait for 1 second
  Then I should see "Using HTTP"
  Then I scroll to cell with "Dhaka" label
  Then I press "Dhaka"
  Then I see an alert with "106 Dhaka" title
  And I see an alert with "Latitude:23.720000 Longitude:90.410000" text
  Then I press "OK"
  Then I wait for 5 seconds
  Then I press "Refresh"
  Then I wait for 1 second
  Then I should see "Using HTTP"
  Then I press "Refresh"
  Then I should see "Using Cached"
  Then I press "Save"
  And take picture


