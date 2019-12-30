% Function name: AutoClear
% Parent scripts: minesweeper, NumDisp
% Function purpose: Recursively clear spaces when the user selects to clear
% a blank space


function [ClearedGrid,gg,FlagGrid] = AutoClear(x,y,BombGrid,FlagGrid,ClearedGrid,Difficulty,gg,blank,loss,mine,b1,b2,b3,b4,b5,b6,b7,b8)
    if x > Difficulty(1) || y > Difficulty(1) || x < 1 || y < 1 % Stop calling if the space is out of bounds
    elseif BombGrid(x,y) == 0 && ClearedGrid(x,y) == 0
        % Clear the selected space if it is blank
        image((x-1)*100+5,(y-1)*100+5,blank)
        ClearedGrid(x,y) = 1;
        
        % Call a 4-connected region around the current space
        [ClearedGrid,gg,FlagGrid] = AutoClear(x+1,y,BombGrid,FlagGrid,ClearedGrid,Difficulty,gg,blank,loss,mine,b1,b2,b3,b4,b5,b6,b7,b8);
        [ClearedGrid,gg,FlagGrid] = AutoClear(x-1,y,BombGrid,FlagGrid,ClearedGrid,Difficulty,gg,blank,loss,mine,b1,b2,b3,b4,b5,b6,b7,b8);
        [ClearedGrid,gg,FlagGrid] = AutoClear(x,y+1,BombGrid,FlagGrid,ClearedGrid,Difficulty,gg,blank,loss,mine,b1,b2,b3,b4,b5,b6,b7,b8);
        [ClearedGrid,gg,FlagGrid] = AutoClear(x,y-1,BombGrid,FlagGrid,ClearedGrid,Difficulty,gg,blank,loss,mine,b1,b2,b3,b4,b5,b6,b7,b8);
    elseif BombGrid(x,y) > 0 && ClearedGrid(x,y) == 0
        
        % Clear a space if it is not blank, do not call surrounding spaces
        [ClearedGrid,gg,FlagGrid] = NumDisp(x,y,BombGrid,FlagGrid,ClearedGrid,Difficulty,gg,blank,loss,mine,b1,b2,b3,b4,b5,b6,b7,b8);
    
    end
end
