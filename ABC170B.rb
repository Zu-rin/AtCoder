def main
    ok = false
    x, y = gets.split(' ').map(&:to_i)
    for i in 0..x do
        if i * 2 + (x - i) * 4 == y
            ok = true
            break
        end
    end
    if ok
        puts "Yes"        
    else
        puts "No"
    end
end


if __FILE__ == $0
    main
end