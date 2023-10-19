
#include "game.h"

game::game(): m_screen(new screen(SCREEN_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT)), 
            m_background(background(BACKGROUND_IMAGE_PATH)),
            m_ball(ball(SCREEN_WIDTH/2, SCREEN_HEIGHT/2)),
            m_paddle(paddle(SCREEN_WIDTH/2)),
            m_brickGrid(brickGrid())
{
    
}

void game::run()
{
    SDL_Event event;
    while(true)
    {
        checkStatus();

        m_screen->clear();

        m_background.draw();
        
        m_brickGrid.draw();
        m_ball.draw();
        m_paddle.draw();
        
        if(m_status == PLAYING)
        {
            if(isInteracting(m_ball, m_paddle) == true)
            {
                handleCollision(m_ball, m_paddle);
            }

            isInteracting_handle(m_ball, m_brickGrid);
            
            m_ball.update();
            m_brickGrid.update();
        }
        
        m_screen->draw();


        if(m_brickGrid.isDistroedAll() == true)
        {
            cout<<"You win"<<endl;
            break;
        }

        while(SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                m_screen->close();
                return;
                break;

            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_LEFT:
                        if(m_status == PLAYING)
                            m_paddle.moveToLeft();
                    break;
                    case SDLK_RIGHT:
                        if(m_status == PLAYING)
                            m_paddle.moveToRight();
                    break;

                    //pause/start the game
                    case SDLK_p:
                    case SDLK_s:
                        if(m_status == PASUE)
                            m_status = PLAYING;
                        else 
                            m_status = PASUE;
                    break;
                    
                    //restart the game;
                    case SDLK_r:
                        m_status = PASUE;
                        
                        m_ball.moveTo(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
                        m_paddle.moveTo(SCREEN_WIDTH/2, SCREEN_HEIGHT-8);
                        m_brickGrid.reset();
                    break;
                }
                break;
            default:
                break;
            }
        }
    }
}

void game::checkStatus()
{
    if(m_status == WIN || m_status == LOSE)
    {
        //do nothing
    }
    else
    {
        //check if ball go below the paddle
        if(m_ball.getY() >= m_screen->m_hieght+10)
        {
            m_status = LOSE;
            cout<<"LOSE"<<endl;
        }
        else if(m_brickGrid.isDistroedAll() == true)
        {
            m_status = WIN;
        }
        if(m_status == PASUE)
        {
            //do nothing
        }
        else
        {
            m_status = PLAYING;
        }
    }
    
}


game::~game()
{
}