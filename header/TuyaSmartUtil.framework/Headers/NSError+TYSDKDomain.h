//
//  NSError+TYDomain.h
//  TuyaSmartBaseKit
//
//  Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)
//

#import <Foundation/Foundation.h>

#define TYErrorDomain @"com.tuya.www"

/**
 *
 * Definitions of error codes
 */
typedef enum {
    
    // The specified network parameter is invalid. The error code cannot be changed.
    TUYA_NETWORK_ERROR = 1500,
    
    // A common error has occurred.
    TUYA_COMMON_ERROR,
    
    // Failed to decompress the panel.
    TUYA_PANEL_DECOMPRESS_ERROR,
    
    // Failed to validate the panel size.
    TUYA_PANEL_SIZE_ERROR,
    
    // Failed to validate local time.
    TUYA_TIME_VALIDATE_FAILED,
    
    // The specified device goes offline.
    TUYA_GW_OFFLINE,
    
    // The specified user has already registered.
    TUYA_USER_HAS_EXISTS,
    
    // The specified DP is illegal and cannot be sent.
    TUYA_ILLEGAL_DP_DATA,
    
    // The device has been reset.
    TUYA_DEVICE_HAS_RESET,
    
    // The user login information is lost.
    TUYA_USER_SESSION_LOSS,
    
    // The user login information is invalid.
    TUYA_USER_SESSION_INVALID,
    
    // An error has occurred while recognizing the QR code.
    TUYA_QR_PROTOCOL_NOT_RECOGNIZED,
    
    // A timeout error has occurred.
    TUYA_TIMEOUT_ERROR,
    
    // Node IDs are unavailable.
    TUYA_NO_AVAILABLE_NODE_ID,
    
    // The format of the specified phone number is invalid.
    TUYA_MOBILE_FORMAT_ERROR,
    
    // The specified phone number is invalid.
    TUYA_MOBILE_ILLEGAL,
    
    // The specified phone verification code is invalid.
    TUYA_MOBILE_CODE_ERROR,
    
    // The format of the specified email address is invalid.
    TUYA_EMAIL_FORMAT_ERROR,
    
    // The specified email address is invalid.
    TUYA_EMAIL_ILLEGAL,
    
    // The specified email verification code is invalid.
    TUYA_EMAIL_CODE_ERROR,
    
    // The specified user does not exist.
    TUYA_USER_NOT_EXISTS,
    
    // Sub-devices of the Zigbee group cannot be empty.
    TUYA_GROUP_DEVICE_LIST_NOT_EMPTY,
    
    // The LAN is disconnected.
    TUYA_SOCKET_TCP_DISCONNECT,
    
    // An error has occurred while resolving domain names over the LAN.
    TUYA_SOCKET_TCP_RESPONSE_ERROR,
    
} TYSDKErrorCode;

@interface NSError (TYSDKDomain)

+ (instancetype)tysdk_errorWithErrorCode:(TYSDKErrorCode)errorCode errorMsg:(NSString *)errorMsg;

+ (NSError *)tysdk_errorWithCodeString:(NSString *)codeString errorMsg:(NSString *)errorMsg;

@end
