//
//  NSBundle+Additions.m
//  Amber
//
//  Created by Keith Duncan on 16/10/2007.
//  Copyright 2007 thirty-three. All rights reserved.
//

#import "NSBundle+Additions.h"

NSString *const AFAlertIconFileKey = @"AFAlertIconFile";

@implementation NSBundle (AKAdditions)

static NSImage *_AFCacheImageFromBundle(NSBundle *bundle, NSString *key) {
	NSImage *image = nil;
	NSString *name = [bundle objectForInfoDictionaryKey:key];
	
	image = [NSImage imageNamed:name];
	if (image != nil) return image;
	
	image = [[NSImage alloc] initWithContentsOfFile:[bundle pathForImageResource:name]];
	[image setName:name];
	
	return image;
}

- (NSImage *)icon {
	return _AFCacheImageFromBundle(self, @"CFBundleIconFile");
}

- (NSImage *)alertIcon {
	return _AFCacheImageFromBundle(self, AFAlertIconFileKey);
}

@end
