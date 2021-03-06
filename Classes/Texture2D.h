//
//  Texture2D.h
//  ParticleEmitterDemo
//
// Copyright (c) 2010 71Squared
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <OpenGLES/ES1/gl.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>


// Enumerators for the different pixel formats this class can handle
typedef enum {
	kTexture2DPixelFormat_Automatic = 0,
	kTexture2DPixelFormat_RGBA8888,
	kTexture2DPixelFormat_RGB565,
	kTexture2DPixelFormat_A8,
} Texture2DPixelFormat;

// The Texture2D class allows any image to be converted into an OpenGL texture.  As
// input this class takes a UIImage instance for the image to be used as a texture
// and also takes a filter.  This filter is used to set the textures Min and Mag filters
// that are used when you scale an image up and down.
//
// OpenGL textures within OpenGL ES 1.1 are termed power or 2 textures.  That means that their
// width and height need to be a power of 2.  This does not mean that the width and height have
// to be the same e.g. 256x256, but they each have to be a power of 2 e.g. 64x128.
//
// Regardless of the size of the image passed in, this class calculates the necessary power of 2 
// size for the texture and provides the necessary information for you to then acces the texture
// or any part of the texture
//
// As the texture generated by this class could be larger than the actual image it contains, two
// variables called maxS and maxT provide the maximum texture coordinates that define the size of 
// the image within the texture.
//
@interface Texture2D : NSObject {

@private
	
	GLuint name;			// Holds the OpenGL name generated for this texture
	CGSize contentSize;		// Stores the actual size of the image being loaded as a texture
	NSUInteger width;		// The actual width and height of the texture once it has been adjusted to be
	NSUInteger height;		// power of 2 compliant
	GLfloat	maxS;			// Maximum texture coordinates for the image that has been placed inside our texture.
	GLfloat	maxT;
    CGSize textureRatio;	// The ratio between pixels and texels (texture coordinates)
    Texture2DPixelFormat pixelFormat;	// The pixel format of the image that has been loaded
}

@property(nonatomic, readonly) GLuint name;
@property(nonatomic, readonly) CGSize contentSize;
@property(nonatomic, readonly) NSUInteger width;
@property(nonatomic, readonly) NSUInteger height;
@property(nonatomic, readonly) GLfloat maxS;
@property(nonatomic, readonly) GLfloat maxT;
@property(nonatomic, readonly) CGSize textureRatio;
@property(nonatomic, readonly) Texture2DPixelFormat pixelFormat;

// Designated initializer that takes a UIImage and a filter (used for the MIN and MAG settings
// of the texture) and creates an OpenGL texture.
- (id) initWithImage:(UIImage*)aImage filter:(GLenum)aFilter;

@end