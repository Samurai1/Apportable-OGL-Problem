

#import <UIKit/UIKit.h>
#import <OpenGLES/EAGL.h>
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>
#import "SingletonGameState.h"
#import "Texture2D.h"
#import "Image.h"
#import "TitleScene.h"
#import "OperationDraculaAppDelegate.h"

/*
 This class wraps the CAEAGLLayer from CoreAnimation into a convenient UIView subclass.
 The view content is basically an EAGL surface you render your OpenGL scene into.
 Note that setting the view non-opaque will only work if the EAGL surface has an alpha channel.
 */



//#define MaxAnimationframes 30
@interface EAGLView : UIView {
	

	
@private
    /* The pixel dimensions of the backbuffer */
	
	
    CGPoint TouchLocation;
    CGPoint TouchLocation2;
	
	GLint backingWidth;
    GLint backingHeight;
    
    EAGLContext *context;
    
    /* OpenGL names for the renderbuffer and framebuffers used to render to this view */
    GLuint viewRenderbuffer, viewFramebuffer;
    
    /* OpenGL name for the depth buffer that is attached to viewFramebuffer, if it exists (0 if it does not exist) */
    GLuint depthRenderbuffer;
	
	/* Time since the last frame was rendered */
	CFTimeInterval lastTime;
	BOOL running;
	
	/* State to define if OGL has been initialised or not */
	BOOL glInitialised;
	
	/* Bounds of the current screen */
	CGRect screenBounds;
	
	// Game State
	SingletonGameState *Manager;
	AbstractScene *Scene;
    BOOL Released;
	BOOL STARTED;
	
	CADisplayLink *displayLink;
}


- (void)renderScene;
- (void)startAnimation;
- (void)stopAnimation;
-(void)DeallocScenes;

@end
