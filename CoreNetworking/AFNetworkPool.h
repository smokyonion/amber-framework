//
//  ANConnectionPool.h
//  Bonjour
//
//  Created by Keith Duncan on 25/12/2008.
//  Copyright 2008 software. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CoreNetworking/AFTransportLayer.h"

@class AFNetworkConnection;

/*!
	@brief
	This class schedules added connections on a run loop. They should be prepared to the scheduled on a background run loop.
 */
@interface AFNetworkPool : NSObject {
 @private
	NSMutableSet *_connections;
}

@property (readonly) NSSet *connections;

- (void)addConnectionsObject:(id <AFTransportLayer>)proxy;
- (void)removeConnectionsObject:(id <AFTransportLayer>)proxy;

- (id <AFTransportLayer>)layerWithValue:(id)value forKey:(NSString *)key;

- (void)close;

@end
