#ifndef ROTARY_ENCODER_H
#define ROTARY_ENCODER_H

class RotaryMouse
{
    int m_output_a;
    int m_output_b;
    int aLastState,aState,bLastState;

    void set(int outputA,int outputB)
    {
        m_output_a=outputA;
        m_output_b=outputB;
        pinMode(m_output_a,INPUT);
        pinMode(m_output_b,INPUT);
        aLastState=digitalRead(m_output_a);
        bLastState=digitalRead(m_output_b);
        
    }
    int getPosition()
    {
        int counter=0;
        aState=digitalRead(m_output_a);
        if(aState!=aLastState)
        {
            if(digitalRead(m_output_b)!=aState)
            {
                counter++;
            }
            else
            {
                counter--;
            }
            return counter;
            
        }
    
    }
};
#endif