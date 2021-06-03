function levelp1(i)
  if i == 1 then
	CreateScene("Level1")
	GenerateGrid("Level1",300,100,0,25,7,2,false,"../Data/Tiles/CubeOrange.png","../Data/Tiles/CubePurple.png")
	AddPlayer("Level1",1,0,0,"../Data/Qbert.png")
	SetScene("Level1")
  elseif i == 2 then
	CreateScene("Level2")
	GenerateGrid("Level2",300,100,0,25,7,3,false,"../Data/Tiles/CubeOrange.png","../Data/Tiles/CubePurple.png","../Data/Tiles/CubeBlue.png")
	AddPlayer("Level2",1,0,0,"../Data/Qbert.png")
	SetScene("Level2")
  elseif i == 3 then
	CreateScene("Level3")
	GenerateGrid("Level3",300,100,0,25,7,2,true,"../Data/Tiles/CubeOrange.png","../Data/Tiles/CubeBlue.png")
	AddPlayer("Level3",1,0,0,"../Data/Qbert.png")
	SetScene("Level3")
  end
end


gameMode = "levelp1"
level = 1