//
// TuyaSmartCommunicationMode.h
// TuyaSmartDeviceCoreKit
//
// Copyright (c) 2014-2021 Tuya Inc. (https://developer.tuya.com)

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Communication type
typedef NS_ENUM(NSUInteger, TYCommunicationType) {
    TYCommunicationTypeLAN      = 0, // LAN
    TYCommunicationTypeMQTT     = 1, // MQTT
    TYCommunicationTypeHTTP     = 2, // Http
    TYCommunicationTypeBLE      = 3, // Single Point Bluetooth
    TYCommunicationTypeSIGMesh  = 4, // Sig Mesh
    TYCommunicationTypeBLEMesh  = 5, // Tuya Private Mesh
    TYCommunicationTypeBLEBeacon  = 6, // beaocn
};

/// Communication mode
@interface TuyaSmartCommunicationMode : NSObject

/// Communication protocol version
@property (nonatomic, assign) double pv;

/// Communication Protocol Type
@property (nonatomic, assign) TYCommunicationType type;

@end

/// Device communication
@interface TuyaSmartCommunication : NSObject

/// Communication sequence
@property (nonatomic, strong) NSArray<TuyaSmartCommunicationMode *> *communicationModes;

/// Communication Nodes
@property (nonatomic, strong) NSString *communicationNode;

@end

NS_ASSUME_NONNULL_END
