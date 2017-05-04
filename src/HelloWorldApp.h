// © You i Labs Inc. 2000-2017. All rights reserved.
#ifndef _HELLO_WORLD_APP_H_
#define _HELLO_WORLD_APP_H_

#include <framework/YiApp.h>
#include <signal/YiSignalHandler.h>

class CYITimeline;

/*!
 \defgroup helloworld HelloWorld
 \brief This basic sample displays a rotating image.
 
 \details <H3>Purpose:</H3>
 To demonstrate how to load a simple view and and to manually trigger animations.
 <H3>Suggested Learning Activities:</H3>
 Modify the animation in the After Effects file (HelloWorld.aep), export the composition using the You.i Engine Affect Effects plugin and launch the application to view the changes.

 */
/*@{*/
class HelloWorldApp : public CYIApp, public CYISignalHandler
{
public:
    HelloWorldApp();
    virtual ~HelloWorldApp();
    
    /*!
        \details Pure virtual of CYIApp.
        \sa CYIApp::UserInit
     */
    virtual bool UserInit();
    /*!
        \details Pure virtual of CYIApp.
        \sa CYIApp::UserStart
     */
    virtual bool UserStart();
    /*!
        \details Signal handler for the spin animation timeline completing.
     */
    void OnSpinAnimationCompleted();

private:

    // Store a pointer to the spin animation timeline
    CYITimeline *m_pSpinAnimation;
};

/*!
 @}
*/

#endif //_HELLO_WORLD_APP_H_
