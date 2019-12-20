function [ClearedGrid,gg,FlagGrid] = NumDisp(x,y,BombGrid,FlagGrid,ClearedGrid,Difficulty,gg,blank,loss,mine,b1,b2,b3,b4,b5,b6,b7,b8)
    if x > Difficulty(1) || y > Difficulty(1) || x < 1 || y < 1
    elseif FlagGrid(x,y) == 1
    elseif BombGrid(x,y) >= 10
        fprintf('Game Over!\n')
        image(Difficulty(1)*50+5,Difficulty(1)*100 + 5,loss)
        % Display all bombs when you lose
        for i = 1:Difficulty(1)
            for j = 1:Difficulty(1)
                if BombGrid(i,j) >= 10
                    image((i-1)*100+5,(j-1)*100+5,mine)
                end
            end
        end
        gg = 1;
    elseif BombGrid(x,y) == 1
        image((x-1)*100+5,(y-1)*100+5,b1)
        ClearedGrid(x,y) = 1;
    elseif BombGrid(x,y) == 2
        image((x-1)*100+5,(y-1)*100+5,b2)
        ClearedGrid(x,y) = 1;
    elseif BombGrid(x,y) == 3
        image((x-1)*100+5,(y-1)*100+5,b3)
        ClearedGrid(x,y) = 1;
    elseif BombGrid(x,y) == 4
        image((x-1)*100+5,(y-1)*100+5,b4)
        ClearedGrid(x,y) = 1;
    elseif BombGrid(x,y) == 5
        image((x-1)*100+5,(y-1)*100+5,b5)
        ClearedGrid(x,y) = 1;
    elseif BombGrid(x,y) == 6
        image((x-1)*100+5,(y-1)*100+5,b6)
        ClearedGrid(x,y) = 1;
    elseif BombGrid(x,y) == 7
        image((x-1)*100+5,(y-1)*100+5,b7)
        ClearedGrid(x,y) = 1;
    elseif BombGrid(x,y) == 8
        image((x-1)*100+5,(y-1)*100+5,b8)
        ClearedGrid(x,y) = 1;
    elseif BombGrid(x,y) == 0
        [ClearedGrid,gg,FlagGrid] = AutoClear(x,y,BombGrid,FlagGrid,ClearedGrid,Difficulty,gg,blank,loss,mine,b1,b2,b3,b4,b5,b6,b7,b8);
    end
end

