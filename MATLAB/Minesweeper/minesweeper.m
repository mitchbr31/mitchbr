clear;clc;close all

%% Load the images

b1 = imread(strcat(pwd,'/images/1.jpg'));
b2 = imread(strcat(pwd,'/images/2.jpg'));
b3 = imread(strcat(pwd,'/images/3.jpg'));
b4 = imread(strcat(pwd,'/images/4.jpg'));
b5 = imread(strcat(pwd,'/images/5.jpg'));
b6 = imread(strcat(pwd,'/images/6.jpg'));
b7 = imread(strcat(pwd,'/images/7.jpg'));
b8 = imread(strcat(pwd,'/images/8.jpg'));
blank = imread(strcat(pwd,'/images/blank.jpg'));
flag = imread(strcat(pwd,'/images/flag.png'));
mine = imread(strcat(pwd,'/images/mine.jpg'));
win = imread(strcat(pwd,'/images/win.jpg'));
loss = imread(strcat(pwd,'/images/loss.jpg'));
normal = imread(strcat(pwd,'/images/normal.jpg'));
X = imread(strcat(pwd,'/images/close.jpg'));

%% Initializing Game

    % Create a prompt to select difficulty
        % Creates Difficulty Matrix of form [wall length, number of mines]
    DiffSelect = listdlg('PromptString', 'Select Your Difficulty:', 'SelectionMode', 'Single', 'ListString', {'Easy', 'Medium', 'Hard'}, 'ListSize', [300 300]);
    if DiffSelect == 1
        Difficulty = [8, 10];
    elseif DiffSelect == 2
        Difficulty = [16, 40];
    elseif DiffSelect == 3
        Difficulty = [22, 99];
    end
    
%% Loop turns until the player closes the game
playing = 1;
while playing == 1
    clc; clf
    % Creating Matrices

    MineGrid = zeros(Difficulty(1),Difficulty(1)); % Matrix storing where mines will be located
    FlagGrid = zeros(Difficulty(1),Difficulty(1)); % Matrix storing where the player has flags active
    ClearedGrid = zeros(Difficulty(1),Difficulty(1)); % Matrix storing locations where the player has already clicked

    
    %% Generating Mine Grid

    % Generating Random Mine Locations
    BombLoc = randperm(Difficulty(1)^2,Difficulty(2));
    for i = 1:length(BombLoc)
        MineGrid(BombLoc(i)) = 10;
        [i,j] = ind2sub([Difficulty(1),Difficulty(1)],BombLoc(i));
        for I = i-1:i+1
            for J = j-1:j+1
                if I > 0 && J > 0 && I <= Difficulty(1) && J <= Difficulty(1)
                    MineGrid(I,J) = MineGrid(I,J) + 1;
                end
            end
        end
    end

    
    %% Creating the UI Plot

    PLim = (Difficulty(1)-1)*100; % Converts the grid numbers into plot limits

    % Plotting the grid lines
    for n = 0:100:PLim
    xBox = [0 0 100 100 0];
    yBox = [0 100 100 0 0];
        for m = 0:100:PLim

            plot(xBox+n, yBox+m, 'k')
            hold on
        end
    end
    % Plotting sprites for mine/flag selection
    image(Difficulty(1)*100 - 195,Difficulty(1)*100 + 5,mine)
    image(Difficulty(1)*100 - 95,Difficulty(1)*100 + 5,flag)
    % Plotting sprites for game status (smiley faces)
    %     and red X (to close the game)
    image(Difficulty(1)*50+5,Difficulty(1)*100 + 5,normal)
    image(Difficulty(1)*50-95,Difficulty(1)*100 + 5,X)
    
    axis equal

    
    %% Initialize variables
    
    mineflag = 0; % Boolean to select mine/flag placement, 0=mine, 1=flag
    image(5,Difficulty(1)*100 + 5,mine)
    gg = 0; next = 0;
    
    %% Player Turns
    
    % While the player hasn't won/lost
    while gg == 0
         % Take player input then convert to values used in matrices
        [x, y] = ginput( 1 );
        x = floor(x/100)+1; y = floor(y/100)+1;
        if x == Difficulty(1) && y == Difficulty(1)+1
            % Switch to flag placement
            mineflag = 1;
            image(5,Difficulty(1)*100 + 5,flag)
        elseif x == Difficulty(1)-1 && y == Difficulty(1)+1
            % Switch to mine clearing
            mineflag = 0;
            image(5,Difficulty(1)*100 + 5,mine)
        elseif x == Difficulty(1)/2 + 1 && y == Difficulty(1) + 1
            % Starts new game
            gg = 1; m = Difficulty(1)/2 + 1; n = Difficulty(1) + 1;
        elseif x == Difficulty(1)/2 && y == Difficulty(1) + 1
            % Closes the game
            gg = 1; next = 1; playing = 0; close all;
        elseif x > Difficulty(1) || y > Difficulty(1) || x < 1 || y < 1
            % Handles inputs outside boundaries
            % Without it the game will crash
        end
        
        % Clear or place flag in cell
        if mineflag == 0
            [ClearedGrid,gg,FlagGrid] = NumDisp(x,y,MineGrid,FlagGrid,ClearedGrid,Difficulty,gg,blank,loss,mine,b1,b2,b3,b4,b5,b6,b7,b8);
        elseif mineflag == 1
            if x > Difficulty(1) || y > Difficulty(1) || x < 1 || y < 1
                % Handles inputs outside boundaries
            elseif ClearedGrid(x,y) == 1
                % Won't let a flag be palced in a cleared cell
            elseif FlagGrid(x,y) == 0
                % Places a flag
                image((x-1)*100+5,(y-1)*100+5,flag)
                FlagGrid(x,y) = 1;
            else
                % Removes a placed flag
                FlagGrid(x,y) = 0;
                image((x-1)*100+5,(y-1)*100+5,imread(strcat(pwd,'/images/white.jpg')));
            end
        end
        
        % Ending the game when all cells without a mine are cleared
        if sum(sum(ClearedGrid)) == Difficulty(1)^2 - Difficulty(2)
            gg = 1;
            fprintf('Congrats! You won!')
            image(Difficulty(1)*50+5,Difficulty(1)*100 + 5,win)
        end
    end

    while next == 0
        
        % Take another player input after the game has ended
        [m, n] = ginput( 1 );
        m = floor(m/100)+1; n = floor(n/100)+1;
        
        if m == Difficulty(1)/2 + 1 && n == Difficulty(1) + 1
            % Starts a new game
            next = 1;
        elseif m == Difficulty(1)/2 && n == Difficulty(1) + 1
            % Closes the game
            next = 1; gg = 1; playing = 0; close all;
        elseif m > Difficulty(1) || n > Difficulty(1) || m < 1 || n < 1
            % Handle inputs outside boundaries
        end
    end

end
