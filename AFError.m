//
//  AFError.m
//  iLog fitness
//
//  Created by Keith Duncan on 21/06/2007.
//  Copyright 2007 thirty-three. All rights reserved.
//

#import "AFError.h"

@implementation AFError

@synthesize type, name, reason;

+ (id)errorWithName:(NSString *)_name reason:(NSString *)_reason {
	return [[[self alloc] initWithType:ERROR name:_name reason:_reason] autorelease];
}

+ (id)warningWithName:(NSString *)_name reason:(NSString *)_reason {
	[[[self alloc] initWithType:WARNING name:_name reason:_reason] autorelease];
}

- (id)initWithType:(errorType)_type name:(NSString *)_name reason:(NSString *)_reason {
	[super init];
	
	self.type = _type;
	
	self.name = _name;
	self.reason = _reason;
	
	return self;
}

- (void)dealloc {
	[name release];
	[reason release];
	
	[super dealloc];
}

- (id)copyWithZone:(NSZone *)zone {
	return [[AFError alloc] initWithType:type name:name reason:reason];
}

- (NSImage *)image {
	return (type == ERROR ? [NSImage errorImage] : [NSImage warningImage]);
}

@end

@implementation NSImage (AFError)

+ (NSImage *)errorImage {
	return [NSImage imageNamed:@"Stop"];
}

+ (NSImage *)warningImage {
	return [NSImage imageNamed:@"Orange Ball"];
}

@end
