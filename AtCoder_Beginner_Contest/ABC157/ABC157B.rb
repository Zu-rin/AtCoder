def main
    a = []
    3.times do |i|
        a.push([false, false, false])
    end
    dic = {}
    3.times do |i|
        d = gets.split.map(&:to_i)
        d.each_with_index do |x, j|
            dic[x] = [i, j]
        end
    end
    num = gets.to_i
    num.times do |i|
        x = gets.to_i
        if dic[x]
            a[dic[x][0]][dic[x][1]] = true
        end
    end
    ok = false
    3.times do |i|
        x, y = true, true
        3.times do |j|
            if not a[i][j]
                x = false
            end
            if not a[j][i]
                y = false
            end
        end
        if x || y
            ok = true
        end
    end
    x, y = true, true
    3.times do |i|
        if not a[i][i]
            x = false
        end
        if not a[i][2-i]
            y = false
        end
    end
    if x || y
        ok = true
    end
    ans = ok ? "Yes" : "No"
    puts ans   
end

if __FILE__ == $0
    main
end