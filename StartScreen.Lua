
function LoadLevel(host, level, playerAmount, versus)

	size = {w = 7, h = 7 }

	if	level == 1 then
		map = {cycle = false, layers = 2 , goal = 2 ,TileArt = {"Tile01.png","Tile02.png"}}
		if playerAmount == 1 then
		player1Pos = {x = 0,y = 0}
		else if versus  = true
		player1Pos = {x = 0,y = 0}
		else	
		player1Pos = {x = -6,y = 6}
		player2Pos = {x = 0,y = 6}
	end
end
