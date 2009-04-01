//
//  ANServer.h
//  Bonjour
//
//  Created by Keith Duncan on 25/12/2008.
//  Copyright 2008 thirty-three software. All rights reserved.
//

#import "CoreNetworking/CoreNetworking.h"

@class AFConnectionPool;

@protocol AFConnectionLayer;
@protocol AFConnectionServerDelegate, AFConnectionLayerHostDelegate;

@interface AFConnectionServer : NSObject <AFConnectionLayerHostDelegate> {
	id <AFConnectionServerDelegate> _delegate;
	AFConnectionPool *hosts, *clients;
}

/*!
	@method
	@abstract	Create a server with ports open on all IP addresses (it equivalent of 0.0.0.0)
	@param		|port| is passed by reference so that if you pass 0 you get back the actual port
 */
+ (id)networkServerWithPort:(SInt32 *)port type:(struct AFSocketType)type;

/*!
	@method
	@abstract	Create a server with ports open on all loopback IP addresses (the equivalent of 127.0.0.1)
 */
+ (id)localhostServerWithPort:(SInt32 *)port type:(struct AFSocketType)type;

/*!
	@method
	@abstract	The returned object is sent [[connectionClass alloc] init] to create a new application layer.
	@discussion	the default implementation raises an unimplemented exception
 */
+ (Class)connectionClass;

/*!
	@method
	@abstract	The delegate is optional in this class, most servers should function without one
 */
@property (assign) id <AFConnectionServerDelegate> delegate;

/*!
	@property
	@abstract	You can add host sockets to this object, the server observes the |connections| property and sets itself as the delegate for any objects
 */
@property (readonly, retain) AFConnectionPool *hosts;

/*!
	@method
	@abstract	this method uses the <tt>+connectionClass</tt>
 */
- (id <AFConnectionLayer>)newApplicationLayerForNetworkLayer:(id <AFConnectionLayer>)socket; // Note: override point, if you need to customize your application layer before it is added to the connection pool, call super for basic setup first

/*!
	@property
 */
@property (readonly, retain) AFConnectionPool *clients;

@end

@protocol AFConnectionServerDelegate <NSObject>
 @optional
- (BOOL)server:(AFConnectionServer *)server shouldConnect:(id <AFConnectionLayer>)connection toHost:(const CFHostRef)addr;
@end
