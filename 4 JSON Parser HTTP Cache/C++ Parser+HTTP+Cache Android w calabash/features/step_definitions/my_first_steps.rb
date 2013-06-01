Given /^the app is running/ do
	macro 'my app is running'
end


Then /^I scroll to cell with "([^\"]*)" label$/ do |text|
    q = query("TextView text:'#{text}'")
    while q.empty?
        performAction('scroll_down')
        q = query("TextView text:'#{text}'")
    end 
end





