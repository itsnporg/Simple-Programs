=begin
  Ruby program to demonstrate Hash.member method
=end	

hsh = {"colors"  => "red",
     "letters" => "a", "Fruit" => "Grapes"}

puts "Hash.member? implementation:"
puts "Enter the Key you want to search:-"
ky = gets.chomp

if (hsh.member?(ky))
	puts "Key found successfully"
else
	puts "Key not found!"
end
