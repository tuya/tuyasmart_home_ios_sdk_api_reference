//
// TuyaSmartHTTPDNS.h
// TuyaSmartBaseKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// @brief TuyaSmartHTTPDNS is another solution for the DNS query instead of the system DNS service.
///
/// The DNS query can be performed over HTTP to prevent DNS cache pollution.
@interface TuyaSmartHTTPDNS : NSObject

+ (instancetype)sharedInstance;

/// The asynchronous resolution API operation. The cache is queried first. If the DNS record is found, the result is returned. Otherwise, the value of nil and asynchronous domain name resolution result is returned to update the cache.
/// @param The domain name, such as www.tuya.com.
/// @return The resolution result of the domain name.
- (NSString *)getIpWithHost:(NSString *)host;


/// Specifies whether the domain name is downgraded.
/// @param host The domain name.
/// @param enable Specifies whether to downgrade the domain name.
- (void)setDegradationWithHost:(NSString *)host enable:(BOOL)enable;

@end

NS_ASSUME_NONNULL_END
