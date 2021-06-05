function levelp1(i)
  if i == 1 then
	CreateScene("Level1")
	GenerateGrid("Level1",300,100,0,32,7,2,false,"../Data/Tiles/CubeYellow.png","../Data/Tiles/CubePurple.png")
	AddPlayer("Level1",1,0,0,"../Data/Qbert.png",true,true)
	SetScene("Level1")
  elseif i == 2 then
	CreateScene("Level2")
	GenerateGrid("Level2",300,100,0,32,7,3,false,"../Data/Tiles/CubeYellow.png","../Data/Tiles/CubePurple.png","../Data/Tiles/CubeBlue.png")
	AddPlayer("Level2",1,0,0,"../Data/Qbert.png",true,true)
	SetScene("Level2")
  elseif i == 3 then
	CreateScene("Level3")
	GenerateGrid("Level3",300,100,0,32,7,2,true,"../Data/Tiles/CubeYellow.png","../Data/Tiles/CubeBlue.png")
	AddPlayer("Level3",1,0,0,"../Data/Qbert.png",true,true)
	SetScene("Level3")
  end
end

function levelp2(i)
  if i == 1 then
	CreateScene("Level1")
	GenerateGrid("Level1",300,100,0,32,7,2,false,"../Data/Tiles/CubeYellow.png","../Data/Tiles/CubePurple.png")
	AddPlayer("Level1",1,6,6,"../Data/Qbert.png",true,true)
	AddPlayer("Level1",2,6,0,"../Data/Qbert.png",true,true)
	SetScene("Level1")
  elseif i == 2 then
	CreateScene("Level2")
	GenerateGrid("Level2",300,100,0,32,7,3,false,"../Data/Tiles/CubeYellow.png","../Data/Tiles/CubePurple.png","../Data/Tiles/CubeBlue.png")
	AddPlayer("Level2",1,6,6,"../Data/Qbert.png",true,true)
	AddPlayer("Level2",2,6,0,"../Data/Qbert.png",true,true)
	SetScene("Level2")
  elseif i == 3 then
	CreateScene("Level3")
	GenerateGrid("Level3",300,100,0,32,7,2,true,"../Data/Tiles/CubeYellow.png","../Data/Tiles/CubeBlue.png")
	AddPlayer("Level3",1,6,6,"../Data/Qbert.png",true,true)
	AddPlayer("Level3",2,6,0,"../Data/Qbert.png",true,true)
	SetScene("Level3")
  end
end

function levelvs(i)
  if i == 1 then
	CreateScene("Level1")
	GenerateGrid("Level1",300,100,0,32,7,2,false,"../Data/Tiles/CubeYellow.png","../Data/Tiles/CubePurple.png")
	AddPlayer("Level1",1,0,0,"../Data/Qbert.png",true,true)
	AddPlayer("Level1",2,1,0,"../Data/Coily.png",false,false)
	SetScene("Level1")
  elseif i == 2 then
	CreateScene("Level2")
	GenerateGrid("Level2",300,100,0,32,7,3,false,"../Data/Tiles/CubeYellow.png","../Data/Tiles/CubePurple.png","../Data/Tiles/CubeBlue.png")
	AddPlayer("Level2",1,0,0,"../Data/Qbert.png",true,true)
	AddPlayer("Level2",2,1,0,"../Data/Coily.png",false,false)
	SetScene("Level2")
  elseif i == 3 then
	CreateScene("Level3")
	GenerateGrid("Level3",300,100,0,32,7,2,true,"../Data/Tiles/CubeYellow.png","../Data/Tiles/CubeBlue.png")
	AddPlayer("Level3",1,0,0,"../Data/Qbert.png",true,true)
	AddPlayer("Level3",2,1,0,"../Data/Coily.png",false,false)
	SetScene("Level3")
  end
end

gameMode = "levelp1"
level = 1
