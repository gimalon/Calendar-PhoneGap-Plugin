#import <Foundation/Foundation.h>
#import <Cordova/CDVPlugin.h>

#ifndef TARGET_IS_EXTENSION
#import <EventKitUI/EventKitUI.h>
#endif

#import <EventKit/EventKit.h>

#ifndef TARGET_IS_EXTENSION
@interface Calendar : CDVPlugin <EKEventEditViewDelegate>
#endif

#ifdef TARGET_IS_EXTENSION
@interface Calendar : CDVPlugin
#endif

@property (nonatomic, retain) EKEventStore* eventStore;
@property (nonatomic, copy) NSString *interactiveCallbackId;

- (void)initEventStoreWithCalendarCapabilities;

-(NSArray*)findEKEventsWithTitle: (NSString *)title
                        location: (NSString *)location
                           notes: (NSString *)notes
                       startDate: (NSDate *)startDate
                         endDate: (NSDate *)endDate
                       calendars: (NSArray *)calendars;

- (void)hasReadPermission:(CDVInvokedUrlCommand*)command;
- (void)requestReadPermission:(CDVInvokedUrlCommand*)command;

- (void)hasWritePermission:(CDVInvokedUrlCommand*)command;
- (void)requestWritePermission:(CDVInvokedUrlCommand*)command;

- (void)hasReadWritePermission:(CDVInvokedUrlCommand*)command;
- (void)requestReadWritePermission:(CDVInvokedUrlCommand*)command;

#ifndef TARGET_IS_EXTENSION
- (void)openCalendar:(CDVInvokedUrlCommand*)command;
#endif

- (void)createCalendar:(CDVInvokedUrlCommand*)command;
- (void)deleteCalendar:(CDVInvokedUrlCommand*)command;

- (void)createEventWithOptions:(CDVInvokedUrlCommand*)command;

#ifndef TARGET_IS_EXTENSION
- (void)createEventInteractively:(CDVInvokedUrlCommand*)command;
#endif 

- (void)modifyEventWithOptions:(CDVInvokedUrlCommand*)command;
- (void)modifyEventWithId:(CDVInvokedUrlCommand*)command;

- (void)findEventWithOptions:(CDVInvokedUrlCommand*)command;
- (void)findAllEventsInNamedCalendar:(CDVInvokedUrlCommand*)command;

- (void)listCalendars:(CDVInvokedUrlCommand*)command;
- (void)deleteEvent:(CDVInvokedUrlCommand*)command;
- (void)deleteEventFromNamedCalendar:(CDVInvokedUrlCommand*)command;
- (void)deleteEventFromCalendar:(CDVInvokedUrlCommand*)command calendar:(EKCalendar*)calendar;
- (void)deleteEventWithId:(CDVInvokedUrlCommand*)command;
#ifndef TARGET_IS_EXTENSION
- (void)eventEditViewController:(EKEventEditViewController*)controller didCompleteWithAction:(EKEventEditViewAction) action;
#endif
@end
