//
//  AFXMLElementPacket.h
//  Amber
//
//  Created by Keith Duncan on 28/06/2009.
//  Copyright 2009. All rights reserved.
//

#import "CoreNetworking/AFPacket.h"

#if TARGET_OS_IPHONE
#import <CFNetwork/CFNetwork.h>
#endif

@class AFPacketRead;

/*!
	@brief
	This packet will read a complete XML chunk and it's contents.
 
	Return Examples:
	
	1. <element/>
	2. <element> </element>
	3. </element>
	
	@detail
	The completed buffer is an NSString, allowing the caller to use whatever XML library is available.
 */
@interface AFXMLElementPacket : AFPacket <AFPacketReading> {
 @private
	NSStringEncoding _encoding;
	
	AFPacketRead *_currentRead;
	
	NSMutableData *_xmlBuffer;
	NSInteger _depth;
}

/*!
	@brief
	Designated Initializer.
 */
- (id)initWithStringEncoding:(NSStringEncoding)encoding;

/*!
	@brief
	This returns the XML buffer as a string, encoded as you specified at initialization.
 */
- (NSString *)buffer;

@end
