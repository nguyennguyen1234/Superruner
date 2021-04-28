

const int WALKING_ANIMATION_FRAMES = 10;
SDL_Rect gSpriteClips[ WALKING_ANIMATION_FRAMES ];
LTexture gSpriteSheetTexture;

const int MONSTER_ANIMATION_FRAMES = 6;
SDL_Rect gSprite[ MONSTER_ANIMATION_FRAMES ];
LTexture gmonstersheet;
LTexture gBGTexture;

const int MONSTER1_ANIMATION_FRAMES = 6;
SDL_Rect gSpritemonster[ MONSTER1_ANIMATION_FRAMES ];
LTexture gmonster1sheet;
LTexture gTextTexture;
LTexture gTextTitle;

const int MONSTER2_ANIMATION_FRAMES = 6;
SDL_Rect gSpritemonster2[ MONSTER2_ANIMATION_FRAMES ];
LTexture gmonster2sheet;
LTexture gScoreTextTexture;
//menu icon
LTexture menuboard;
LTexture muteicon;
LTexture soundicon;
LTexture button1;
LTexture exitbutton;
LTexture playbutton;
LTexture resumebutton;
LTexture helpsbutton;
LTexture xbutton;
LTexture helpboard;
LTexture gameoverboard;
LTexture overbutton;
LTexture overexitbutton;

//music var
//The music that will be played
Mix_Music *gMusic = NULL;

//The sound effects that will be used
Mix_Chunk *gJump = NULL;
Mix_Chunk *Lose = NULL;
Mix_Chunk *gMedium = NULL;
Mix_Chunk *gLow = NULL;


bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "NGUYEN DUC NGUYEN", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}

				if( TTF_Init() == -1 )
				{
					printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
					success = false;
				}

				 //Initialize SDL_mixer
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
				{
					printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	 // Set menu board
	    if( !menuboard.loadFromFile( "menuboard.png" ) )
	{
		printf( "Failed to load menu texture!\n" );
		success = false;
	}
	//set play button
	if( !playbutton.loadFromFile( "playbutton.png" ) )
	{
		printf( "Failed to load play texture!\n" );
		success = false;
	}
	//set helpsbutton
	if( !helpsbutton.loadFromFile( "helpsbutton.png" ) )
	{
		printf( "Failed to load help texture!\n" );
		success = false;
	}
	//set exit button
	if( !exitbutton.loadFromFile( "exitbutton.png" ) )
	{
		printf( "Failed to load exit texture!\n" );
		success = false;
	}

	if( !xbutton.loadFromFile( "xbutton.png" ) )
	{
		printf( "Failed to load x texture!\n" );
		success = false;
	}
	//set resume button
	if( !resumebutton.loadFromFile( "resumebutton.png" ) )
	{
		printf( "Failed to load menu texture!\n" );
		success = false;
	}
	//set mute icon
        if( !muteicon.loadFromFile( "muteicon.png" ) )
	{
		printf( "Failed to load muteicon texture!\n" );
		success = false;
	}
	//set sound icon

	if( !soundicon.loadFromFile( "soundicon.png" ) )
	{
		printf( "Failed to load soundicon texture!\n" );
		success = false;
	}

	if( !button1.loadFromFile( "button1.png" ) )
	{
		printf( "Failed to load button1 texture!\n" );
		success = false;
	}
	//load helpboard
	if( !helpboard.loadFromFile( "helpboard.png" ) )
	{
		printf( "Failed to load helpboard texture!\n" );
		success = false;
	}

	//load gameover board
	if( !gameoverboard.loadFromFile( "gameoverboard.png" ) )
	{
		printf( "Failed to load button1 texture!\n" );
		success = false;
	}

	//load overbutton
	if( !overbutton.loadFromFile( "overbutton.png" ) )
	{
		printf( "Failed to load overbutton texture!\n" );
		success = false;
	}

	//load helpboard
	if( !overexitbutton.loadFromFile( "overexitbutton.png" ) )
	{
		printf( "Failed to load overexitbutton texture!\n" );
		success = false;
	}


	//Load sprite sheet texture
	if( !gSpriteSheetTexture.loadFromFile( "main.png" ) )
	{
		printf( "Failed to load walking animation texture!\n" );
		success = false;
	}
	else
	{

		//Set sprite clips
		gSpriteClips[ 0 ].x =   0;
		gSpriteClips[ 0 ].y =   20;
		gSpriteClips[ 0 ].w =  160;
		gSpriteClips[ 0 ].h = 215;

		/*gSpriteClips[ 1 ].x =  192;
		gSpriteClips[ 1 ].y =   0;
		gSpriteClips[ 1 ].w =  192;
		gSpriteClips[ 1 ].h = 192;*/

		gSpriteClips[ 1 ].x = 160;
		gSpriteClips[ 1 ].y =   20;
		gSpriteClips[ 1 ].w = 160;
		gSpriteClips[ 1 ].h = 210;

		/*gSpriteClips[ 3 ].x = 576;
		gSpriteClips[ 3 ].y =   0;
		gSpriteClips[ 3 ].w =  192;
		gSpriteClips[ 3 ].h = 192;*/

		gSpriteClips[ 2 ].x = 320;
		gSpriteClips[ 2 ].y =   20;
		gSpriteClips[ 2 ].w = 160;
		gSpriteClips[ 2 ].h = 210;

		/*gSpriteClips[ 5 ].x = 960;
		gSpriteClips[ 5 ].y =   0;
		gSpriteClips[ 5 ].w = 192;
		gSpriteClips[ 5 ].h = 192;*/

		gSpriteClips[ 3 ].x = 480;
		gSpriteClips[ 3 ].y =   20;
		gSpriteClips[ 3 ].w = 160;
		gSpriteClips[ 3 ].h = 210;

		/*gSpriteClips[ 7 ].x = 1344;
		gSpriteClips[ 7 ].y =   0;
		gSpriteClips[ 7 ].w =  192;
		gSpriteClips[ 7 ].h = 192;*/

		gSpriteClips[ 4 ].x = 640;
		gSpriteClips[ 4 ].y =   20;
		gSpriteClips[ 4 ].w = 160;
		gSpriteClips[ 4 ].h = 210;

		/*gSpriteClips[ 9 ].x = 1728;
		gSpriteClips[ 9 ].y =   0;
		gSpriteClips[ 9 ].w =  192;
		gSpriteClips[ 9 ].h = 192;*/

		gSpriteClips[ 5 ].x =0 ;
		gSpriteClips[ 5 ].y =220;
		gSpriteClips[ 5 ].w =160;
		gSpriteClips[ 5 ].h = 220;

		/*gSpriteClips[ 6 ].x = 192;
		gSpriteClips[ 6 ].y = 192;
		gSpriteClips[ 6 ].w =192;
		gSpriteClips[ 6 ].h = 192;*/

		gSpriteClips[ 6 ].x = 160;
		gSpriteClips[ 6 ].y = 220;
		gSpriteClips[ 6 ].w = 160;
		gSpriteClips[ 6 ].h = 220;

		gSpriteClips[ 7 ].x = 320;
		gSpriteClips[ 7 ].y = 220;
		gSpriteClips[ 7 ].w = 160;
		gSpriteClips[ 7 ].h = 220;


		gSpriteClips[ 8 ].x = 480;
		gSpriteClips[ 8 ].y = 220;
		gSpriteClips[ 8 ].w = 160;
		gSpriteClips[ 8 ].h = 220;

		gSpriteClips[ 9 ].x = 640;
		gSpriteClips[ 9 ].y = 220;
		gSpriteClips[ 9 ].w = 160;
		gSpriteClips[ 9 ].h = 220;

	}

	if( !gmonstersheet.loadFromFile( "monster2.png" ) )
	{
		printf( "Failed to load walking animation texture!\n" );
		success = false;
	}
	else
	{
		//Set sprite clips
		gSprite[ 0 ].x =  0;
		gSprite[ 0 ].y =  0;
		gSprite[ 0 ].w = 150;
		gSprite[ 0 ].h = 158;

		gSprite[ 1 ].x = 150;
		gSprite[ 1 ].y =   0;
		gSprite[ 1 ].w = 150;
		gSprite[ 1 ].h = 158;

		gSprite[ 2 ].x = 300;
		gSprite[ 2 ].y = 0;
		gSprite[ 2 ].w = 150;
		gSprite[ 2 ].h = 158;

		gSprite[ 3 ].x = 0;
		gSprite[ 3 ].y = 160;
		gSprite[ 3 ].w = 150;
		gSprite[ 3 ].h = 158;

		gSprite[ 4 ].x = 150;
		gSprite[ 4 ].y = 160;
		gSprite[ 4 ].w = 150;
		gSprite[ 4 ].h = 158;

		gSprite[ 5 ].x = 300;
		gSprite[ 5 ].y = 160;
		gSprite[ 5 ].w = 150;
		gSprite[ 5 ].h = 158;
	}

	if( !gmonster1sheet.loadFromFile( "monster3.png" ) )
	{
		printf( "Failed to load walking animation texture!\n" );
		success = false;
	}
	else
	{
		//Set sprite clips
		gSpritemonster[ 0 ].x =  0;
		gSpritemonster[ 0 ].y = 117;
		gSpritemonster[ 0 ].w = 150;
		gSpritemonster[ 0 ].h = 116;

		gSpritemonster[ 1 ].x = 150;
		gSpritemonster[ 1 ].y =   117;
		gSpritemonster[ 1 ].w = 150;
		gSpritemonster[ 1 ].h = 116;

		gSpritemonster[ 2 ].x = 300;
		gSpritemonster[ 2 ].y = 117;
		gSpritemonster[ 2 ].w = 150;
		gSpritemonster[ 2 ].h = 116;

		gSpritemonster[ 3 ].x =  0;
		gSpritemonster[ 3 ].y = 117;
		gSpritemonster[ 3 ].w = 150;
		gSpritemonster[ 3 ].h = 116;

		gSpritemonster[ 4 ].x = 150;
		gSpritemonster[ 4 ].y =   117;
		gSpritemonster[ 4 ].w = 150;
		gSpritemonster[ 4 ].h = 116;

		gSpritemonster[ 5 ].x = 300;
		gSpritemonster[ 5 ].y = 117;
		gSpritemonster[ 5 ].w = 150;
		gSpritemonster[ 5 ].h = 116;



	}

    if( !gmonster2sheet.loadFromFile( "monster5.png" ) )
	{
		printf( "Failed to load walking animation texture!\n" );
		success = false;
	}
	else
	{
		//Set sprite clips
		gSpritemonster2[ 0 ].x = 0;
		gSpritemonster2[ 0 ].y = 0;
		gSpritemonster2[ 0 ].w = 150;
		gSpritemonster2[ 0 ].h = 150;

		gSpritemonster2[ 1 ].x = 150;
		gSpritemonster2[ 1 ].y = 0;
		gSpritemonster2[ 1 ].w = 150;
		gSpritemonster2[ 1 ].h = 150;

		gSpritemonster2[ 2 ].x = 300;
		gSpritemonster2[ 2 ].y = 0;
		gSpritemonster2[ 2 ].w = 150;
		gSpritemonster2[ 2 ].h = 150;

		gSpritemonster2[ 3 ].x =  0;
		gSpritemonster2[ 3 ].y = 150;
		gSpritemonster2[ 3 ].w = 150;
		gSpritemonster2[ 3 ].h = 150;

		gSpritemonster2[ 4 ].x = 150;
		gSpritemonster2[ 4 ].y = 150;
		gSpritemonster2[ 4 ].w = 150;
		gSpritemonster2[ 4 ].h = 150;

		gSpritemonster2[ 5 ].x = 300;
		gSpritemonster2[ 5 ].y = 150;
		gSpritemonster2[ 5 ].w = 150;
		gSpritemonster2[ 5 ].h = 150;



	}

	if( !gBGTexture.loadFromFile( "gamebackground.png" ) )
	{
		printf( "Failed to load background texture!\n" );
		success = false;
	}
    //load fonts
	gFont = TTF_OpenFont( "ALGER.ttf", 100 );
	gTest = TTF_OpenFont("BAUHS93.TTF",40);
	gTitle=TTF_OpenFont("COOPBL.TTF",120);
	if( gFont == NULL &&gTest==NULL&&gTitle==NULL)
	{
		printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	}
	else
	{
	    SDL_Color titleColor ={250,0,0};
		//Render text
		SDL_Color textColor = { 250, 0, 0 };
		if( !gTextTexture.loadFromRenderedText( "GAME OVER ", textColor, gFont ) )
		{
			printf( "Failed to render text texture!\n" );
			success = false;
		}
		if(!gTextTitle.loadFromRenderedText("SUPER RUNNER",titleColor,gTitle))
        {
			printf( "Failed to render text texture!\n" );
			success = false;
		}
	}

	// load music
	gMusic = Mix_LoadMUS( "backgroundmusic.mp3" );
	if( gMusic == NULL )
	{
		printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}

	gJump = Mix_LoadWAV( "jump2.wav" );
	if( gJump == NULL )
	{
		printf( "Failed to load jump sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}

    Lose = Mix_LoadWAV( "losing.wav" );
	if( Lose == NULL )
	{
		printf( "Failed to load jump sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
		success = false;
	}

	//Load sound effects
	return success;
}

void close()
{
    //Free global font
	TTF_CloseFont( gFont );
	gFont = NULL;

	//Free loaded images
	gSpriteSheetTexture.free();
	gBGTexture.free();
    gmonstersheet.free();
    gmonster1sheet.free();
    //gRock.free();

    //Free the music
	Mix_FreeMusic( gMusic );
	gMusic = NULL;

    //Free the sound effects
	Mix_FreeChunk( gJump );
	gJump = NULL;

	Mix_FreeChunk( Lose );
	Lose = NULL;
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
/*if (e.type == SDL_WINDOWEVENT)
                    {


                        SDL_GetWindowSize(gWindow, &SCREEN_WIDTH, &SCREEN_HEIGHT);
                        y=SCREEN_HEIGHT-SCREEN_HEIGHT/5-150;
                        //z=SCREEN_WIDTH;
                       // black=1.5*SCREEN_WIDTH;

                    }*/
                    //int y=SCREEN_HEIGHT-210;
					//User requests quit
