
//Using SDL, SDL_image, standard IO, vectors, and strings
#include"window.h"
#include"ltexture.h"
#include"runfunction.h"
#include"moseclick.h"

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{

            SDL_GetWindowSize(gWindow, &SCREEN_WIDTH, &SCREEN_HEIGHT);
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;


			//Set text color as black
			SDL_Color textColor = { 250,0, 0, 255 };

            //score text
            std::stringstream ScoreText;

			// counting score
			int score=0;

        //The background scrolling offset
			int scrollingOffset = 0;

			//Current animation frame
			int frame = 0;
			int x=100;
            int y=SCREEN_HEIGHT-SCREEN_HEIGHT/5-150;
			int framemonster=0;
			int framemonster1=0;
			int framemonster2=0;
			//monster0 position
			int z=1.25*SCREEN_WIDTH;
			//controlling background speed
			int i=0;
			int t=1;
			//controlling monster speed
			int dem=0;
			//monster1 position
			int black=2.75*SCREEN_WIDTH;
			//monster2 position
			int wizard= 2*SCREEN_WIDTH;
			//monster speed var
			int speed=5;



			//run check
			//bool run=false;

			// score var
            bool check =true;
			Mix_PlayMusic( gMusic, -1 );
			//While application is running
			while( !quit )
			{
			    //get title
			    if(mouse==true)gTextTitle.render( ( SCREEN_WIDTH - gTextTitle.getWidth() ) / 2, ( SCREEN_HEIGHT - gTextTitle.getHeight() ) / 12 );
				while( SDL_PollEvent( &e ) != 0 )
				{
				    if(!sound)Mix_PauseMusic();else Mix_ResumeMusic();

				    gButtons.handleEvent(e);
				    if(checkquit)quit=true;




					if( e.type == SDL_QUIT || e.key.keysym.sym==SDLK_ESCAPE&&e.type==SDL_KEYDOWN  )
					{
						quit = true;
					}
					if(y<SCREEN_HEIGHT-SCREEN_HEIGHT/5-150)y+=250;
					else if( e.type == SDL_KEYDOWN&&check&&run==true )
					{
						//Select surfaces based on key press
						switch( e.key.keysym.sym )
						{

							case SDLK_RIGHT:
							{
							x=x+10;
							//score+=10;
							if(x>=SCREEN_WIDTH-160)
                            {
                                x -= 10;
                               // score-=10;
                            }


							break;}
							case SDLK_LEFT:
							{
							x=x-10;
							if(x==0)
                            {
                                x += 10;
                            }


							break;}
							case SDLK_UP:
							{
                               if(sound==true) Mix_PlayChannel( -1, gJump, 0 );

                                y=y-250;
                                //x=x+velocity;
                                if((SCREEN_WIDTH-(x+100))<250&&(SCREEN_WIDTH-(x+100))>0)
                                {
                                    x=SCREEN_WIDTH-160;
                                    //score+=160;
                                }
                                else {x=x+250;}



                                if(x>=SCREEN_WIDTH-100)
                            {
                            x -= 250;
                            }

							break;

                            }
                            case SDLK_SPACE:
                            {
                                 resume =true;
                                mouse=false;
                                help=false;
                                run=false;
                                checkresume=true;
                                checkclick=false;
                                break;
                            }
						}
					}


				}

                dem++;
				 i++;
				 if(run==true)
                {
                 z-=speed;
                 black-=speed;
                 wizard-=speed;
                }
                 if(dem==3000&&run)
                 {
                     speed+=3;
                     dem=0;
                 }

                if(sound==true)soundicon.render(55,5);
                else muteicon.render(55,5);

                button1.render(0,5);



                //Set text to be rendered
				ScoreText.str( "" );
				ScoreText << "SCORE:  " << score;

				//Render text
				if( !gScoreTextTexture.loadFromRenderedText( ScoreText.str().c_str(), textColor,gTest ) )
				{
					printf( "Unable to render score texture!\n" );
				}

				gScoreTextTexture.render(  20, 50 );

				//Update screen
				//SDL_RenderPresent( gRenderer );

                //load menu board
                 SDL_Rect Menuclip;
                 Menuclip.w=SCREEN_WIDTH/2;
                 Menuclip.h=SCREEN_HEIGHT*0.75;
                if (mouse||resume) menuboard.render(SCREEN_WIDTH*0.25,SCREEN_HEIGHT*0.15,&Menuclip);

                if (help==true) helpboard.render(SCREEN_WIDTH*0.25,SCREEN_HEIGHT*0.1,&Menuclip);

                //Set button click
                if (mouse) playbutton.render(SCREEN_WIDTH*0.43,SCREEN_HEIGHT*0.4);

                if (mouse||resume) helpsbutton.render(SCREEN_WIDTH*0.43,SCREEN_HEIGHT*0.4+130);

                if (mouse||resume) exitbutton.render(SCREEN_WIDTH*0.43,SCREEN_HEIGHT*0.4+260);

                if (resume) resumebutton.render(SCREEN_WIDTH*0.43,SCREEN_HEIGHT*0.4);

                if (help==true) xbutton.render(SCREEN_WIDTH*0.25+Menuclip.w-100,SCREEN_HEIGHT*0.1+100);

                 //Render current frame
				SDL_Rect monsterClip = gSprite[ framemonster / 6 ];
				//monsterClip.w=200;
				//monsterClip.h=100;
				gmonstersheet.render( z, SCREEN_HEIGHT*0.8-100 , &monsterClip );
				//Update screen
				//SDL_RenderPresent( gRenderer );
				//Go to next frame
				framemonster++;

				//Cycle animation
				if( framemonster / 6 >= MONSTER_ANIMATION_FRAMES )
				{
					framemonster = 0;
				}
				//if(z<-300)z=SCREEN_WIDTH+700;

				//Render current frame monster1
				SDL_Rect monster1Clip = gSpritemonster[ framemonster1 / 6 ];
				gmonster1sheet.render( black, SCREEN_HEIGHT*0.8-100 , &monster1Clip );
				//Update screen
				//SDL_RenderPresent( gRenderer );
				//Go to next frame
				framemonster1++;

				if( framemonster1 / 6 >= MONSTER1_ANIMATION_FRAMES )
				{
					framemonster1 = 0;
				}

                //Cycle animation monster2
				//Render current frame
				SDL_Rect monster2Clip = gSpritemonster2[ framemonster2 / 6 ];
				gmonster2sheet.render( wizard, SCREEN_HEIGHT*0.8-100 , &monster2Clip );
				//Update screen
				//SDL_RenderPresent( gRenderer );
				//Go to next frame
				framemonster2++;

				//Cycle animation
				if( framemonster2 / 6 >= MONSTER2_ANIMATION_FRAMES )
				{
					framemonster2 = 0;
				}

				// set monster position again
				if(black<-150)black=SCREEN_WIDTH*2;
				if(z<-150)z=SCREEN_WIDTH*2;
                if(wizard<-150)wizard=SCREEN_WIDTH*2;

				//Render current frame main
				SDL_Rect currentClip = gSpriteClips[ frame / 10 ];
				gSpriteSheetTexture.renderelse( x, y , &currentClip );

				//Go to next frame
				frame+=2;

				//Cycle animation
				if( frame / 10 >= WALKING_ANIMATION_FRAMES )
				{
					frame = 0;
				}

				//load menu board
                    SDL_Rect Gameoverclip;
                    Gameoverclip.w=SCREEN_WIDTH/2;
                    Gameoverclip.h=SCREEN_HEIGHT*0.75;
                    if(check==false)gameoverboard.render(SCREEN_WIDTH*0.25,SCREEN_HEIGHT*0.15,&Gameoverclip);
                    if(check==false)overbutton.render(SCREEN_WIDTH*0.35,SCREEN_HEIGHT*0.75);
                    if(check==false)overexitbutton.render(SCREEN_WIDTH*0.6,SCREEN_HEIGHT*0.75);
				//Update screen
				SDL_RenderPresent( gRenderer );





                SDL_Rect BGClip = {0, 0, 1.5*SCREEN_WIDTH, SCREEN_HEIGHT};

				//Scroll background
				scrollingOffset=scrollingOffset-t;
				if( scrollingOffset < -(BGClip.w) )
				{
					scrollingOffset = 0;
				}
				if (i==1000){
                        t++;
                        i=0;}

				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				//Render background
				//SDL_Rect BGClip = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
				gBGTexture.render( scrollingOffset,0,&BGClip );
				gBGTexture.render( scrollingOffset + BGClip.w,0,&BGClip );


				if(check&&run)score=score+1;
                //check collision
				if((z<=x+(currentClip.w-30)&&z>=x)||(black<=(x+currentClip.w-30)&&black>=x)||(wizard<=(x+currentClip.w-50)&&wizard>=x))
                {
                    z+=speed;
                    black+=speed;
                    wizard+=speed;
                    gTextTexture.render( ( SCREEN_WIDTH - gTextTexture.getWidth() ) / 2, ( SCREEN_HEIGHT - gTextTexture.getHeight() ) / 2 );

                    if (check&&sound)Mix_PlayChannel( -1, Lose, 0 );
                    check=false;

                }
                if (reset)
                {
                    check=true;
                     x=100;
                     black=2.75*SCREEN_WIDTH;
                     wizard= 2*SCREEN_WIDTH;
                     speed=5;
                     z=1.25*SCREEN_WIDTH;
                    score=0;
                    SDL_Delay(50);
                    t=1;
                    reset=false;


                }




            }

		}
	}

	printf("%d",SCREEN_WIDTH);
	//Free resources and close SDL
	close();

	return 0;
}
