//
//  OpenSSLHelper.h
//  nRFMeshProvision
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#if TARGET_OS_IOS

#import <Foundation/Foundation.h>

@interface TYSDKOpenSSLHelper : NSObject
- (NSData*) calculateSalt: (NSData*) someData;
- (NSData*) calculateCMAC: (NSData*) someData andKey: (NSData*) aKey;
- (NSData*) calculateCCM: (NSData*) someData withKey:(NSData*) aKey nonce:(NSData *) aNonce dataSize:(UInt8) aSize andMICSize:(UInt8) aMICSize;
- (NSData*) obfuscateENCPDU: (NSData*) anENCPDUData cTLTTLValue:(NSData*) aCTLTTLValue sequenceNumber:(NSData*) aSeq ivIndex:(NSData*) anIVIndex privacyKey:(NSData*) aPrivacyKey andsrcAddr:(NSData*) aSrc;
- (NSData*) deobfuscateENCPDU: (NSData*) anENCPDUData ivIndex:(NSData*) anIVIndex privacyKey:(NSData*) aPrivacyKey;
- (NSData*) calculateDecryptedCCM:(NSData *)someData withKey:(NSData *)aKey nonce:(NSData *)aNonce dataSize:(UInt8)aSize andMIC:(NSData*)aMIC;

// MARK: - Helpers
- (NSData*) calculateK1WithN: (NSData*) anNValue salt: (NSData*) aSaltValue andP: (NSData*) aPValue;
- (NSData*) calculateK2WithN: (NSData*) anNValue andP: (NSData*) aPValue;
- (NSData*) calculateK3WithN: (NSData*) anNValue;
- (NSData*) calculateK4WithN: (NSData*) anNValue;
- (NSData*) calculateEvalueWithData: (NSData*) someData andKey: (NSData*) aKey;
@end

#endif
