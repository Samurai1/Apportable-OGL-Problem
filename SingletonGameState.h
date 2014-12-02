
//

#import <Foundation/Foundation.h>
#import <OpenGLES/ES1/gl.h>



@interface SingletonGameState : NSObject {
	
	//Currently bound texture
	GLuint currentlyBoundTexture;

	
}

@property (nonatomic, assign) GLuint currentlyBoundTexture;

+ (SingletonGameState*)sharedGameStateInstance;


@end
