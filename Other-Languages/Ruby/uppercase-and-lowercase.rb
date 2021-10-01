def stringUpperAndLowerCase()

    text = "PrograMMing iS fUN!"

    puts "Original text is: #{text}"

    puts

    puts "From API"
    puts "upper: #{text.upcase}"
    puts "lower: #{text.downcase}"

    puts

    puts "Manual"
    puts "upper: #{toUpper(text)}"
    puts "lower: #{toLower(text)}" 

end

def toUpper( text )

    result = ""

    for i in 0..text.length - 1

        char = text[i]

        if char >= 'a' and char <= 'z'

            distance = char.ord - 'a'.ord
            result += ('A'.ord + distance).chr
        else
            result += char
        end
    end

    return result
end

def toLower( text )

    result = ""

    for i in 0..text.length - 1
        
        char = text[i]

        if char >= 'A' and char <= 'Z'

            distance = char.ord - 'A'.ord
            result += ('a'.ord + distance).chr
        else
            result += char
        end
    end

    return result 
end

stringUpperAndLowerCase()
