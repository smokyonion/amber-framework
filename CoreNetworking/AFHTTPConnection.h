//
//  HTTPConnection.h
//  CoreNetworking
//
//  Created by Keith Duncan on 29/04/2009.
//  Copyright 2009 thirty-three. All rights reserved.
//

#import "CoreNetworking/AFNetworkConnection.h"

#import "CoreNetworking/AFConnectionLayer.h"

@class AFPacketQueue;

/*
	HTTP verbs required for REST access
 */

extern NSString *const HTTPMethodGET;
extern NSString *const HTTPMethodPOST;
extern NSString *const HTTPMethodPUT;
extern NSString *const HTTPMethodDELETE;

/*
	AFHTTPConnection Schemes
 */

extern NSString *const AFNetworkSchemeHTTP;
extern NSString *const AFNetworkSchemeHTTPS;

/*!
	@brief
	This class is indended to sit on top of AFNetworkTransport and provides HTTP messaging semantics.
 */
@interface AFHTTPConnection : AFNetworkConnection <AFConnectionLayer> {
	CFHTTPAuthenticationRef _authentication;
	NSDictionary *_authenticationCredentials;
	
	AFPacketQueue *_transactionQueue;
}

+ (NSString *)userAgent;
+ (void)setUserAgent:(NSString *)userAgent;

- (CFHTTPAuthenticationRef)authentication;
- (void)setAuthentication:(CFHTTPAuthenticationRef)authentication;

@property (copy) NSDictionary *authenticationCredentials;

/*!
	@brief
	This method doesn't start a transation. It simply passes the data on to the |lowerLayer| for writing.
 */
- (void)performWrite:(CFHTTPMessageRef)message forTag:(NSUInteger)tag withTimeout:(NSTimeInterval)duration;

/*!
	@brief
	This method enqueues a transaction, which pairs a request with it's response.
	
	@result
	The data written to the socket, complete with the headers added internally.
 */
- (NSData *)performMethod:(NSString *)HTTPMethod onResource:(NSString *)resource withHeaders:(NSDictionary *)headers withBody:(NSData *)body;

@end

@interface AFHTTPConnection (Delegate) <AFTransportLayerControlDelegate, AFTransportLayerDataDelegate>

@end