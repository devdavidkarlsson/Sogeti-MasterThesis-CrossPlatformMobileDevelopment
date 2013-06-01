Given /^I am on the Welcome Screen$/ do
  element_exists("view")
  sleep(STEP_PAUSE)
end

Then /^I scroll to cell with "([^\"]*)" label$/ do |name|
    wait_poll(:until_exists => "label text:'#{name}'", :timeout => 5) do
        scroll("tableView", :down)
    end
end

Then /^I see an alert with "([^\"]*)" title$/ do |title|
    wait_poll(:until_exists => "label text:'#{title}'", :timeout => 5) do
        result = query("label text:'#{title}'").empty?
        if result
            screenshot_and_raise "could not find text field with AlertView with title '#{title}'"
        end
        sleep(STEP_PAUSE)
    end
end

Then /^I see an alert with "([^\"]*)" text$/ do |message|
    wait_poll(:until_exists => "label text:'#{message}'", :timeout => 5) do
        result = query("label text:'#{message}'").empty?
        if result
            screenshot_and_raise "could not find text field with AlertView with text '#{message}'"
        end
        sleep(STEP_PAUSE)
    end
end