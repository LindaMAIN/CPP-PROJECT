#include "mario.h"
#include "block.h"
#include "questionblock.h"
#include "brick.h"
#include "mushroom.h"
#include "enemy.h"
#include <QGraphicsPixmapItem>
#include <cmath>


Mario::Mario()
    : m_big(false), m_fliped(false), m_hurt(false), m_dead(false), m_velocityX(0.0f), m_velocityY(0.0f), m_elapsedTime(0.0f), m_onGround(false),
      m_runMode(false), m_crouchning(false), m_collideWithBlock(true)
{
    createAnimations();
    setMaxX(20000);
    m_hurtTimer = HURT_TIMER;
    m_deadTimer = DEAD_TIMER;
}

void Mario::createAnimations()
{
    m_texture = QPixmap(":/res/mario_items_18x18.png");
    const float TSW = GLOBAL::MARIO_TEXTURE_SIZE.width(); //TextureSizeWidth
    const float TSH = GLOBAL::MARIO_TEXTURE_SIZE.height();//TextureSizeWidth
    const float TS  = GLOBAL::TILE_SIZE.width();          //TileWidth
    const float TH  = GLOBAL::TILE_SIZE.height();         //TileHeight
    //0 4 1frame
    m_animator.m_mapStates["idle"].push_back(m_texture.copy(0,4*TSH, TSW,TSH)
                                             .scaled(TS, TH));
    m_animator.m_mapStates["idle_f_"].push_back(m_texture.copy(0,4*TSH, TSW,TSW)
                                                .scaled(TS, TH).transformed(QTransform().scale(-1,1)));

    //2 4 1frame
    m_animator.m_mapStates["jump"].push_back(m_texture.copy(2*TSW,4*TSH, TSW,TSH)
                                             .scaled(TS, TH));
    m_animator.m_mapStates["jump_f_"].push_back(m_texture.copy(2*TSW,4*TSH, TSW,TSH)
                                                .scaled(TS, TH).transformed(QTransform().scale(-1,1)));
    //4 4 3frames
    m_animator.m_mapStates["run"].push_back(m_texture.copy(4*TSW,4*TSH, TSW,TSH)
                                            .scaled(TS, TH));
    m_animator.m_mapStates["run"].push_back(m_texture.copy(5*TSW,4*TSH, TSW,TSH)
                                            .scaled(TS, TH));
    m_animator.m_mapStates["run"].push_back(m_texture.copy(6*TSW,4*TSH, TSW,TSH)
                                            .scaled(TS, TH));

    m_animator.m_mapStates["run_f_"].push_back(m_texture.copy(4*TSW,4*TSH, TSW,TSH)
                                               .scaled(TS, TH).transformed(QTransform().scale(-1,1)));
    m_animator.m_mapStates["run_f_"].push_back(m_texture.copy(5*TSW,4*TSH, TSW,TSH)
                                               .scaled(TS, TH).transformed(QTransform().scale(-1,1)));
    m_animator.m_mapStates["run_f_"].push_back(m_texture.copy(6*TSW,4*TSH, TSW,TSH)
                                               .scaled(TS, TH).transformed(QTransform().scale(-1,1)));
    //3 4 1frame
    m_animator.m_mapStates["die"].push_back(m_texture.copy(3*TSW,4*TSH, TSW,TSH)
                                            .scaled(TS, TH));

    m_animator.m_mapStates["die_f_"].push_back(m_texture.copy(3*TSW,4*TSH, TSW,TSH)
                                               .scaled(TS, TH).transformed(QTransform().scale(-1, 1)));
    ///////////////////////////BIG//////////////////////
    //0 0  1frame
    m_animator.m_mapStates["idle_b_"].push_back(m_texture.copy(0,0*TSH, TSW,2*TSH)
                                                .scaled(TS, 2*TH));
    m_animator.m_mapStates["idle_b__f_"].push_back(m_texture.copy(0,0*TSH, TSW,2*TSH)
                                                   .scaled(TS, 2*TH).transformed(QTransform().scale(-1,1)));
    //2 0 1frame
    m_animator.m_mapStates["jump_b_"].push_back(m_texture.copy(2*TSW,0*TSH, TSW,2*TSH)
                                                .scaled(TS, 2*TH));
    m_animator.m_mapStates["jump_b__f_"].push_back(m_texture.copy(2*TSW,0*TSH, TSW,2*TSH)
                                                   .scaled(TS, 2*TH).transformed(QTransform().scale(-1,1)));

    //0 4 3frames
    m_animator.m_mapStates["run_b_"].push_back(m_texture.copy(4*TSW,0*TSH, TSW,2*TSH)
                                               .scaled(TS, 2*TH));
    m_animator.m_mapStates["run_b_"].push_back(m_texture.copy(5*TSW,0*TSH, TSW,2*TSH)
                                               .scaled(TS, 2*TH));
    m_animator.m_mapStates["run_b_"].push_back(m_texture.copy(6*TSW,0*TSH, TSW,2*TSH)
                                               .scaled(TS, 2*TH));

    m_animator.m_mapStates["run_b__f_"].push_back(m_texture.copy(4*TSW,0*TSH, TSW,2*TSH)
                                                  .scaled(TS, 2*TH).transformed(QTransform().scale(-1,1)));
    m_animator.m_mapStates["run_b__f_"].push_back(m_texture.copy(5*TSW,0*TSH, TSW,2*TSH)
                                                  .scaled(TS, 2*TH).transformed(QTransform().scale(-1,1)));
    m_animator.m_mapStates["run_b__f_"].push_back(m_texture.copy(6*TSW,0*TSH, TSW,2*TSH)
                                                  .scaled(TS, 2*TH).transformed(QTransform().scale(-1,1)));

    //0 3 1frame
    m_animator.m_mapStates["crouching_b_"].push_back(m_texture.copy(3*TSW,0*TSH, TSW,2*TSH)
                                                     .scaled(TS, 2*TH));
    m_animator.m_mapStates["crouching_b__f_"].push_back(m_texture.copy(3*TSW,0*TSH, TSW,2*TSH)
                                                        .scaled(TS, 2*TH).transformed(QTransform().scale(-1,1)));


    m_animator.changeState("idle");
    m_animator.m_timeBetweenFrames = 0.25f;
}

void Mario::jump(float jumpSpeed)
{
    m_velocityY = jumpSpeed;
}

void Mario::handleHurtCounter(float elapsedTime)
{
    if(m_hurt && !m_dead)
    {
        m_hurtTimer -= elapsedTime;
        if(m_hurtTimer < 0.0f)
        {
            m_hurtTimer = HURT_TIMER;
            m_hurt = false;
        }
    }
}

void Mario::handleDeadCounter(float elapsedTime)
{
    if(m_dead && m_collideWithBlock)
    {
        m_deadTimer -= elapsedTime;
        if(m_deadTimer < 0.0f)
        {
            jump(-0.75*JUMP_SPEED*elapsedTime);
            m_deadTimer = DEAD_TIMER;
            m_collideWithBlock = false;
        }
    }
}

void Mario::setHurt()
{
    m_hurt = true;
    if(m_big)
    {
        m_big = false;
        setPosition(position().x(), position().y()+GLOBAL::TILE_SIZE.height());
    }
    else
    {
        m_dead = true;
    }
}

void Mario::draw(GameScene &scene)
{
    QGraphicsPixmapItem* pItem = new QGraphicsPixmapItem();
    pItem->setZValue(GLOBAL::MARIO_LAYER);
    pItem->setPos(int(position().x()), int(position().y()));
    if(m_hurt && !m_dead)
    {
        int val = m_hurtTimer*10;
        if(val%2)
        {
            pItem->setPixmap(m_animator.pixmap());
        }
    }
    else
    {
        pItem->setPixmap(m_animator.pixmap());
    }
    scene.addItem(pItem);
}

void Mario::chooseAnimation()
{
    setFliped();
    if(m_onGround && std::fabs(m_velocityX) > 1.f)
    {
        setAnimatationState("run");

    }
    if(m_onGround && std::fabs(m_velocityX) < 0.5f)
    {
        if(m_crouchning)
        {
            setAnimatationState("crouching");
        }
        else
        {
            setAnimatationState("idle");
        }
    }
    if(!m_onGround){
        setAnimatationState("jump");
    }
    if(m_dead)
    {
        setAnimatationState("die");
    }
}

void Mario::update(float elapsedTime)
{
    m_velocityY += GLOBAL::GRAVITY;
    // Drag
    if (m_onGround)
    {
        m_velocityX += -DRAG_VALUE * m_velocityX * elapsedTime;

        if (std::fabs(m_velocityX) < 0.01f)
        {
            m_velocityX = 0.0f;
        }
    }
    clampVelocities(elapsedTime);
    if(m_collideWithBlock)
    {
        checkCollisionWithBlocks();
    }
    checkCollisionWithMushrooms();
    checkCollisionWithEnemies();
    setPosition(int(position().x() + m_velocityX), int(position().y() + m_velocityY));
    //Boundary
    if(position().x() < 0.0f)
    {
        setX(0.0f);
    }
    if(position().y() > GLOBAL::SCREEN_SIZE.height()+2*GLOBAL::TILE_SIZE.height())
    {
        setY(GLOBAL::SCREEN_SIZE.height()+3*GLOBAL::TILE_SIZE.height());
        setHurt();
        setHurt();
    }
    if(position().x() > m_maxX - GLOBAL::TILE_SIZE.width())
    {
        setX(m_maxX - GLOBAL::TILE_SIZE.width());
    }
    // Set Animation
    chooseAnimation();

    handleHurtCounter(elapsedTime);
    handleDeadCounter(elapsedTime);
}

void Mario::update(float elapsedTime, GameScene &scene)
{
    m_elapsedTime = elapsedTime;
    if(!m_dead)//isAlive
    {
        bool leftPressed =      scene.keys(GLOBAL::A_KEY)->m_held ||
                                scene.keys(GLOBAL::LEFT_ARROW_KEY)->m_held;
        bool rightPressed =     scene.keys(GLOBAL::D_KEY)->m_held ||
                                scene.keys(GLOBAL::RIGHT_ARROW_KEY)->m_held;
        bool jumpPressed =      scene.keys(GLOBAL::W_KEY)->m_held ||
                                scene.keys(GLOBAL::UP_ARROW_KEY)->m_held ||
                                scene.keys(GLOBAL::SPACE_KEY)->m_held;
        bool crouchingPressed = scene.keys(GLOBAL::S_KEY)->m_held ||
                                scene.keys(GLOBAL::DOWN_ARROW_KEY)->m_held;

        if(leftPressed)
        {
            //in air mario is less control(0.75) than on ground
            if(m_runMode)
            {
                m_velocityX += (m_onGround ? -RUN_SPEED : -0.75f*RUN_SPEED) * elapsedTime;
            }
            else
            {
                m_velocityX += (m_onGround ? -MOVE_SPEED : -0.75*MOVE_SPEED) * elapsedTime;
            }
        }
        if(rightPressed)
        {
            //in air mario is less control(0.75) than on ground
            if(m_runMode)
            {
                m_velocityX += (m_onGround ? +RUN_SPEED : +0.75f*RUN_SPEED) * elapsedTime;
            }
            else
            {
                m_velocityX += (m_onGround ? +MOVE_SPEED : +0.75*MOVE_SPEED) * elapsedTime;
            }
        }
        if(jumpPressed)
        {
            //m_velocityY < std::fabs(1.f) <= read value is before gravity works
            if (m_onGround && !int(m_velocityY))
            {
                //m_velocityY = -JUMP_SPEED * elapsedTime;
                jump(-JUMP_SPEED * elapsedTime);
                //nDirModX = 1;
            }
        }
        if(crouchingPressed)
        {
            if(!leftPressed && !rightPressed && m_big)
            {
                m_crouchning = true;
            }
        }
        else
        {
            m_crouchning = false;
        }
    }


    update(elapsedTime);
    m_animator.update(elapsedTime);
}

void Mario::setBig(bool on)
{
    if(on && !m_big)
    {
        setPosition(position().x(), position().y()-GLOBAL::TILE_SIZE.height());
    }
    m_big = on;
}

bool Mario::isBig() const
{
    return m_big;
}

void Mario::resetStatus()
{
    m_big              = false;
    m_fliped           = false;
    m_velocityX        = 0.0f;
    m_velocityY        = 0.0f;
    m_onGround         = false;
    m_runMode          = false;
    m_crouchning       = false;
    m_hurt             = false;
    m_dead             = false;
    m_collideWithBlock = true;
    m_hurtTimer        = HURT_TIMER;
    m_deadTimer        = DEAD_TIMER;
    setPosition(0,0);
}

void Mario::setMaxX(int maxX)
{
    m_maxX = maxX;
}

void Mario::clampVelocities(float elapsedTime)
{
    if(m_runMode && m_velocityX > MAX_RUN_SPEED*elapsedTime)
    {
        m_velocityX = MAX_RUN_SPEED*elapsedTime;
    }
    else if (!m_runMode && m_velocityX > MAX_MOVE_SPEED*elapsedTime )
    {
        m_velocityX = MAX_MOVE_SPEED*elapsedTime;
    }

    if(m_runMode && m_velocityX < -MAX_RUN_SPEED*elapsedTime)
    {
        m_velocityX = -MAX_RUN_SPEED*elapsedTime;
    }
    else if (!m_runMode && m_velocityX < -MAX_MOVE_SPEED*elapsedTime)
    {
        m_velocityX = -MAX_MOVE_SPEED*elapsedTime;
    }

    if (m_velocityY > MAX_FALLDOWN_SPEED*elapsedTime)
    {
        m_velocityY = MAX_FALLDOWN_SPEED*elapsedTime;
    }

    //    if (fPlayerVelY < -100.0f)
    //    {
    //        fPlayerVelY = -100.0f;
    //    }
}

void Mario::collideWithBlock(Block* block)
{
    // Calculate potential new position
    float CollideX;
    float CollideY;
    float shrinkPixel = 5.f, shrinkFactor = 0.9f;//For one tile row, column to avoid block

    //X-axis
    if (m_velocityX <= 0.0f) // Moving Left
    {
        CollideX = position().x() + m_velocityX;
        if(block->hitBox().contains(CollideX, position().y())
                ||
                block->hitBox().contains(CollideX, position().y()+hitBox().height()))
        {
            m_velocityX = 0.0f;
        }
    }
    else // Moving Right
    {
        CollideX = position().x() + hitBox().width() + m_velocityX;
        if(block->hitBox().contains(CollideX, position().y())
                ||
                block->hitBox().contains(CollideX, position().y()+hitBox().height()))
        {
            m_velocityX = 0.0f;
        }
    }
    //Y-axis
    if (m_velocityY < 0.0f) // Moving Up
    {
        m_onGround = false;
        CollideY = position().y() + m_velocityY;
        if(block->hitBox().contains(position().x()+shrinkPixel, CollideY)
                ||
                block->hitBox().contains(position().x()+shrinkFactor*hitBox().width() , CollideY))
        {
            QuestionBlock* questionBlock = dynamic_cast<QuestionBlock*>(block);
            if(questionBlock)
            {
                if(questionBlock->isActivate())
                {
                    questionBlock->deactivate();
                }
            }
            Brick* brick = dynamic_cast<Brick*>(block);
            if(brick)
            {
                if(isBig())
                {
                    brick->destroy();
                }

            }
            m_velocityY = 0.1f;

        }
    }
    else // Moving Down
    {
        CollideY = position().y() + hitBox().height() + m_velocityY;
        if(block->hitBox().contains(position().x()+shrinkPixel, CollideY)
                ||
                block->hitBox().contains(position().x()+shrinkFactor*hitBox().width() , CollideY))
        {
            m_velocityY = 0.0f;
            m_onGround = true;
        }
    }
}

void Mario::checkCollisionWithMushrooms()
{
    foreach(Mushroom* mushroom, Mushroom::MUSHROOMS)
    {
        collideWithMushroom(mushroom);
    }
}

void Mario::collideWithMushroom(Mushroom *mushroom)
{
    if(hitBox().contains(int(mushroom->position().x()), int(mushroom->y()))
            ||
            hitBox().contains(int(mushroom->position().x()+mushroom->hitBox().width()), int(mushroom->y()))
            ||
            hitBox().contains(int(mushroom->position().x()), int(mushroom->y()+mushroom->hitBox().height()))
            ||
            hitBox().contains(int(mushroom->position().x()+mushroom->hitBox().width()), int(mushroom->y()+mushroom->hitBox().height()))
            )
    {
        mushroom->hit();
        setBig(true);
    }
}

void Mario::checkCollisionWithEnemies()
{
    for(int i = 0; i < Enemy::ENEMIES.size(); ++i)
    {
        collideWithEnemy(Enemy::ENEMIES.at(i));
    }
}

void Mario::collideWithEnemy(Enemy *enemy)
{
    // Calculate potential new position
    float CollideX;
    float CollideY;
    float shrinkPixel = 5.f, shrinkFactor = 0.9f;//For one tile row, column to avoid block

    //X-axis
    if (m_velocityX <= 0.0f) // Moving Left
    {
        CollideX = position().x() + m_velocityX;
        if(enemy->hitBox().contains(CollideX, position().y())
                ||
                enemy->hitBox().contains(CollideX, position().y()+hitBox().height()))
        {
            if(enemy->isAlive() && !m_hurt)
            {
                setHurt();
            }

        }
    }
    else // Moving Right
    {
        CollideX = position().x() + hitBox().width() + m_velocityX;
        if(enemy->hitBox().contains(CollideX, position().y())
                ||
                enemy->hitBox().contains(CollideX, position().y()+hitBox().height()))
        {
            if(enemy->isAlive() && !m_hurt)
            {
                setHurt();
            }
        }
    }
    //Y-axis
    if (m_velocityY < 0.0f) // Moving Up
    {
        CollideY = position().y() + m_velocityY;
        if(enemy->hitBox().contains(position().x()+shrinkPixel, CollideY)
                ||
                enemy->hitBox().contains(position().x()+shrinkFactor*hitBox().width() , CollideY))
        {
            if(enemy->isAlive()&& !m_hurt)
            {
                setHurt();
            }
        }
    }
    else if(m_velocityY > 1.f)// Moving Down
    {
        CollideY = position().y() + hitBox().height() + m_velocityY;
        if(enemy->hitBox().contains(position().x()+shrinkPixel, CollideY)
                ||
                enemy->hitBox().contains(position().x()+shrinkFactor*hitBox().width() , CollideY))
        {
            if(enemy->isAlive())
            {
                enemy->setAlive(false);
                jump(-JUMP_SPEED/4.0f*m_elapsedTime);
            }
        }
    }
}

void Mario::setAnimatationState(QString state)
{
    //if big, add to state '_b_'
    if(m_big)
    {
        state += "_b_";
    }
    //if fliped, add to state '_f_'
    if(m_fliped)
    {
        state += "_f_";
    }
    m_animator.changeState(state);
}

void Mario::setFliped()
{
    if(!m_fliped && m_velocityX < -.5f)
    {
        m_fliped = true;
    }
    else if(m_fliped && m_velocityX > .5f)
    {
        m_fliped = false;
    }
}

void Mario::checkCollisionWithBlocks()
{

    for(int i = 0; i < Block::BLOCKS.size(); ++i)
    {
        Brick* brick = dynamic_cast<Brick*>(Block::BLOCKS.at(i));
        if(brick)
        {
            if(brick->isDestroyed())
            {
                continue;
            }
        }
        collideWithBlock(Block::BLOCKS.at(i));
    }
}

QRect Mario::hitBox()
{
    float height;
    float y = position().y();
    if(m_big)
    {
        height = 2*GLOBAL::TILE_SIZE.height();
    }
    else
    {
        height = GLOBAL::TILE_SIZE.height();
    }
    if(m_crouchning)
    {
        y -= GLOBAL::TILE_SIZE.height();
    }
    return QRect(position().x(), y, GLOBAL::TILE_SIZE.width(), height);
}
