def main
    i = 1
    l = []
    n = gets.to_i
    while i * i <= n
        l << ((n / i) - i).abs + n - (n / i * i)
        i += 1
    end
    pp l.min
end 

if __FILE__ == $0
    main
end