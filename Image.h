

#import <Foundation/Foundation.h>
#import "SingletonGameState.h"
#import "Texture2D.h"



@interface UIImage (NoCaching)
+ (id) imageNamedNoCache:(NSString *)name;
@end

@implementation UIImage (NoCaching)

+ (id) imageNamedNoCache:(NSString *)name
{
	NSString *basename = [name stringByDeletingPathExtension];
	NSString *extension = [name pathExtension];
	NSString *path = [[NSBundle mainBundle] pathForResource:basename ofType:extension];
	return [[[UIImage alloc] initWithContentsOfFile:path] autorelease];
}

@end



typedef struct _CFilter {
	GLubyte r;
	GLubyte g;
	GLubyte b;
	GLubyte a;
} CFilter;


typedef struct _Vertex {
	float u[2];
	float uv[2];
	CFilter color;
}Vertex;

typedef struct _Quad2 {
	float tl_x, tl_y;
	float tr_x, tr_y;
	float bl_x, bl_y;
	float br_x, br_y;
} Quad2;

	

@interface Image : NSObject {
	
	GLuint TextureName;
	
	BOOL TextureAllocated;
	
	
	
	// Game State
	SingletonGameState *sharedGameState;
	// The OpenGL texture to be used for this image
	Texture2D		*texture;	
	// The width of the image
	NSUInteger		imageWidth;
	// The height of the image
	NSUInteger		imageHeight;
	// The texture coordinate width to use to find the image
	NSUInteger		textureWidth;
	// The texture coordinate height to use to find the image
	NSUInteger		textureHeight;
	// The maximum texture coordinate width maximum 1.0f
	float			maxTexWidth;
	// The maximum texture coordinate height maximum 1.0f
	float			maxTexHeight;
	// The texture width to pixel ratio
	float			texWidthRatio;
	// The texture height to pixel ratio
	float			texHeightRatio;
	// The X offset to use when looking for our image
	NSUInteger		textureOffsetX;
	// The Y offset to use when looking for our image
	NSUInteger		textureOffsetY;
	// Angle to which the image should be rotated
	float			rotation;
	// Scale at which to draw the image
	float			scaleX;
	float			scaleY;
	// Flip horizontally
	BOOL			flipHorizontally;
	// Flip Vertically
	BOOL			flipVertically;
	// Colour Filter = Red, Green, Blue, Alpha
	float			colourFilter[4];

	// Vertex arrays
	Quad2			*vertices;
	Quad2			*texCoords;
}

@property (nonatomic) GLuint					TextureName;

@property(nonatomic, readonly)Texture2D			*texture;
@property(nonatomic)NSUInteger					imageWidth;
@property(nonatomic)NSUInteger					imageHeight;
@property(nonatomic, readonly)NSUInteger		textureWidth;
@property(nonatomic, readonly)NSUInteger		textureHeight;
@property(nonatomic, readonly)float				texWidthRatio;
@property(nonatomic, readonly)float				texHeightRatio;
@property(nonatomic)NSUInteger					textureOffsetX;
@property(nonatomic)NSUInteger					textureOffsetY;
@property(nonatomic)float						rotation;
@property(nonatomic)float						scaleX;
@property(nonatomic)float						scaleY;
@property(nonatomic) BOOL						flipVertically;
@property(nonatomic) BOOL						flipHorizontally;
@property(nonatomic)Quad2						*vertices;
@property(nonatomic)Quad2						*texCoords;

- (id)initWithImage:(UIImage *)image controlfile:(NSString *)controlfile  ForceRGB565:(BOOL)Force565;
- (void)renderAtPoint:(CGPoint)point centerOfImage:(BOOL)center;
- (void)calculateVerticesAtPoint:(CGPoint)point subImageWidth:(GLuint)subImageWidth subImageHeight:(GLuint)subImageHeight centerOfImage:(BOOL)center;
- (void)calculateTexCoordsAtOffset:(CGPoint)offsetPoint subImageWidth:(GLuint)subImageWidth subImageHeight:(GLuint)subImageHeight;

-(float)getAlpha;
-(void)setAlpha:(float)alpha;


@end
