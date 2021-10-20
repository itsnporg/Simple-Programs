def multiply(num)
    for i in 1..10
        puts "#{num} x #{i} = #{num * i}"
    end
end

while true
    print "Enter a number to create multiplication table: "
    num =  gets.chomp()
    
    if num == ".exit"
        puts "Exit Requested"
        break
    end

    puts "Multiplication table of #{num} is:\n\n"
    multiply num.to_i
    puts "\n"
end
