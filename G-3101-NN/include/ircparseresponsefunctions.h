#ifndef _IRCPARSERESPONSEFUNCTIONS_H_
#define _IRCPARSERESPONSEFUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********************************************************************
ERR_BADCHANMASK 476

The given channel mask was invalid 
********************************************************************/
long IRCParse_ErrBadChanMask(char *strin, char **prefix, char **nick, char **channel, char **msg);

/********************************************************************
ERR_BADCHANNELKEY 475

Returned when attempting to join a key-locked channel either
without a key or with the wrong key 
********************************************************************/
long IRCParse_ErrBadChannelKey(char *strin, char **prefix, char **nick, char **channel, char **msg);

/********************************************************************
RPL_BANLIST 367

A ban-list item
********************************************************************/
long IRCParse_RplBanList(char *strin, char **prefix, char **nick, char **channel, char **banmask, char **server, char **timeleft);

/********************************************************************
ERR_BANNEDFROMCHAN 474

Returned when attempting to join a channel a user is banned from 
********************************************************************/
long IRCParse_ErrBannedFromChan(char *strin, char **prefix, char **nick, char **channel, char **msg);

/********************************************************************
ERR_CHANNELISFULL 471

Returned when attempting to join a channel which is set +l and is
already full 
********************************************************************/
long IRCParse_ErrChannelListFull(char *strin, char **prefix, char **nick, char **channel, char **msg);

/********************************************************************
RPL_CHANNELMODEIS 324

Mode of channel
********************************************************************/
long IRCParse_RplChannelModeIs(char *strin, char **prefix, char **nick, char **channel, char **modetxt);

/********************************************************************
ERR_CHANOPRIVSNEEDED 482

Any strin requiring 'chanop' privileges (such as
MODE messages) MUST return this error if the client
making the attempt is not a chanop on the specified
channel.
********************************************************************/
long IRCParse_ErrChanOPrivsNeeded(char *strin, char **prefix, char **nick, char **channel, char **msg);

/********************************************************************
RPL_ENDOFBANLIST 368

When listing the active 'bans' for a given channel,
a server is required to send the list back using the
RPL_BANLIST and RPL_ENDOFBANLIST messages.  A separate
RPL_BANLIST is sent for each active banmask.  After the
banmasks have been listed (or if none present) a
RPL_ENDOFBANLIST MUST be sent.
********************************************************************/
long IRCParse_RplEndOfBanList(char *strin, char **prefix, char **nick, char **channel, char **msg);

/********************************************************************
RPL_ENDOFEXCEPTLIST 349

When listing the 'exception masks' for a given channel,
a server is required to send the list back using the
RPL_EXCEPTLIST and RPL_ENDOFEXCEPTLIST messages.  A
separate RPL_EXCEPTLIST is sent for each active mask.
After the masks have been listed (or if none present)
a RPL_ENDOFEXCEPTLIST MUST be sent.
********************************************************************/
long IRCParse_RplEndOfExceptList(char *strin, char **prefix, char **nick, char **channel, char **msg);

/********************************************************************
RPL_ENDOFINVITELIST 347

When listing the 'invitations masks' for a given channel,
a server is required to send the list back using the
RPL_INVITELIST and RPL_ENDOFINVITELIST messages.  A
separate RPL_INVITELIST is sent for each active mask.
After the masks have been listed (or if none present) a
RPL_ENDOFINVITELIST MUST be sent.
********************************************************************/
long IRCParse_RplEndOfInviteList(char *strin, char **prefix, char **nick, char **channel, char **msg);

/********************************************************************
RPL_ENDOFNAMES 366

To reply to a NAMES message, a reply pair consisting
of RPL_NAMREPLY and RPL_ENDOFNAMES is sent by the
server back to the client.  If there is no channel
found as in the query, then only RPL_ENDOFNAMES is
returned.  The exception to this is when a NAMES
message is sent with no parameters and all visible
channels and contents are sent back in a series of
RPL_NAMEREPLY messages with a RPL_ENDOFNAMES to mark
the end.
********************************************************************/
long IRCParse_RplEndOfNames(char *strin, char **prefix, char **nick, char **channel, char **msg);

/********************************************************************
RPL_EXCEPTLIST 348

When listing the 'exception masks' for a given channel,
a server is required to send the list back using the
RPL_EXCEPTLIST and RPL_ENDOFEXCEPTLIST messages.  A
separate RPL_EXCEPTLIST is sent for each active mask.
After the masks have been listed (or if none present)
a RPL_ENDOFEXCEPTLIST MUST be sent.
********************************************************************/
long IRCParse_RplExceptList(char *strin, char **prefix, char **nick, char **channel, char **exceptionmask);

/********************************************************************
RPL_INVITELIST 346

When listing the 'invitations masks' for a given channel,
a server is required to send the list back using the
RPL_INVITELIST and RPL_ENDOFINVITELIST messages.  A
separate RPL_INVITELIST is sent for each active mask.
After the masks have been listed (or if none present) a
RPL_ENDOFINVITELIST MUST be sent.
              "<channel> <invitemask>"
********************************************************************/
long IRCParse_RplInviteList(char *strin, char **prefix, char **nick, char **channel, char **invitemask);

/********************************************************************
ERR_INVITEONLYCHAN 473

Any strin requiring operator privileges to operate
MUST return this error to indicate the attempt was
unsuccessful.
********************************************************************/
long IRCParse_ErrInviteOnlyChan(char *strin, char **prefix, char **nick, char **channel, char **msg);

/********************************************************************
RPL_INVITING 341

Returned by the server to indicate that the
attempted INVITE message was successful and is
being passed onto the end client.
********************************************************************/
long IRCParse_RplInviting(char *strin, char **prefix, char **nick, char **nick2, char **channel);

/********************************************************************
ERR_KEYSET 467

Any strin requiring operator privileges to operate
MUST return this error to indicate the attempt was
unsuccessful.
********************************************************************/
long IRCParse_ErrKeySet(char *strin, char **prefix, char **nick, char **channel, char **msg);

/********************************************************************
RPL_LISTSTART 321

Obsolete.
********************************************************************/
long IRCParse_RplListStart(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
RPL_LIST 322

Replies RPL_LIST, RPL_LISTEND mark the actual replies
with data and end of the server's response to a LIST
strin.  If there are no channels available to return,
only the end reply MUST be sent.
              "<channel> <# visible> :<topic>"
********************************************************************/
long IRCParse_RplList(char *strin, char **prefix, char **nick, char **channel, char **visible, char **topic);

/********************************************************************
RPL_LISTEND 323

Replies RPL_LIST, RPL_LISTEND mark the actual replies
with data and end of the server's response to a LIST
strin.  If there are no channels available to return,
only the end reply MUST be sent.
********************************************************************/
long IRCParse_RplListEnd(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
RPL_NAMREPLY 353

The RPL_WHOREPLY and RPL_ENDOFWHO pair are used
to answer a WHO message.  The RPL_WHOREPLY is only
sent if there is an appropriate match to the WHO
query.  If there is a list of parameters supplied
with a WHO message, a RPL_ENDOFWHO MUST be sent
after processing each list item with <name> being
the item.
********************************************************************/
long IRCParse_RplNamReply(char *strin, char **prefix, char **nick, char **name);

/********************************************************************
ERR_NOCHANMODES 477

Any strin requiring operator privileges to operate
MUST return this error to indicate the attempt was
unsuccessful.
********************************************************************/
long IRCParse_ErrNoChanModes(char *strin, char **prefix, char **nick, char **channel, char **msg);

/********************************************************************
ERR_NOSUCHCHANNEL 403

Used to indicate the given channel name is invalid.
********************************************************************/
long IRCParse_ErrNoSuchCannel(char *strin, char **prefix, char **nick, char **channelname, char **msg);

/********************************************************************
ERR_NOTONCHANNEL 442

Returned by the server whenever a client tries to
perform a channel affecting strin for which the
client isn't a member.
********************************************************************/
long IRCParse_ErrNotOnChannel(char *strin, char **prefix, char **nick, char **nick2, char **channel, char **msg);

/********************************************************************
RPL_NOTOPIC 331

When sending a TOPIC message to determine the
channel topic, one of two replies is sent.  If
the topic is set, RPL_TOPIC is sent back else
RPL_NOTOPIC.
********************************************************************/
long IRCParse_RplNoTopic(char *strin, char **prefix, char **nick, char **channel, char **topic);

/********************************************************************
ERR_TOOMANYCHANNELS 405

Sent to a user when they have joined the maximum
number of allowed channels and they try to join
another channel.
********************************************************************/
long IRCParse_ErrTooManyChannels(char *strin, char **prefix, char **nick, char **channelname, char **msg);

/********************************************************************
ERR_TOOMANYMATCHES 416

Returned when too many matches have been found for a strin and
the output has been truncated. An example would be the WHO strin,
where by the mask '*' would match everyone on the network! Ouch!
********************************************************************/
long IRCParse_ErrTooManyMatches(char *strin, char **prefix, char **nick, char **errstrin, char **mask, char **info);

/********************************************************************
ERR_UNKNOWNMODE 472

Any strin requiring operator privileges to operate
MUST return this error to indicate the attempt was
unsuccessful.
********************************************************************/
long IRCParse_ErrUnknownMode(char *strin, char **prefix, char **nick, char **modechar, char **channel, char **msg);

/********************************************************************
ERR_USERNOTINCHANNEL 441

Returned by the server to indicate that the target
user of the strin is not on the given channel.
              "<nick> <channel> :They aren't on that channel"
********************************************************************/
long IRCParse_ErrUserNotInChannel(char *strin, char **prefix, char **nick, char **nick2, char **channel, char **msg);

/********************************************************************
ERR_USERONCHANNEL 443

Returned when a client tries to invite a user to a
channel they are already on.
********************************************************************/
long IRCParse_ErrUserOnChannel(char *strin, char **prefix, char **nick, char **user, char **channel, char **msg);

/********************************************************************
RPL_UNIQOPIS 325

Unique Operator
********************************************************************/
long IRCParse_RplUniqOpIs(char *strin, char **prefix, char **nick, char **channel, char **nickname);

/********************************************************************
RPL_TOPIC 332

When sending a TOPIC message to determine the
channel topic, one of two replies is sent.  If
the topic is set, RPL_TOPIC is sent back else
RPL_NOTOPIC.
********************************************************************/
long IRCParse_RplTopic(char *strin, char **prefix, char **nick, char **channel, char **topic);









/********************************************************************
ERR_NEEDMOREPARAMS

Returned by the server by numerous strins to
indicate to the client that it didn't supply enough
parameters.
********************************************************************/
long IRCParse_ErrNeedMoreParams(char *strin, char **prefix, char **nick, char **failedstring, char **msg);

/********************************************************************
ERR_NONICKNAMEGIVEN

Returned when a nickname parameter expected for a
strin and isn't found.
********************************************************************/
long IRCParse_ErrNoNickNameGiven(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
ERR_NOSUCHSERVER

Used to indicate the server name given currently
does not exist.
********************************************************************/
long IRCParse_ErrNoSuchServer(char *strin, char **prefix, char **nick, char **servername, char **msg);

/********************************************************************
ERR_PASSWDMISMATCH

Returned to indicate a failed attempt at registering
a connection for which a password was required and
was either not given or incorrect.

********************************************************************/
long IRCParse_ErrPasswdMismatch(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
ERR_RESTRICTED

Sent by the server to a user upon connection to indicate
the restricted nature of the connection (user mode "+r").
********************************************************************/
long IRCParse_ErrRestricted(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
ERR_UNAVAILRESOURCE

Returned by a server to a user trying to join a channel
currently blocked by the channel delay mechanism.

Returned by a server to a user trying to change nickname
when the desired nickname is blocked by the nick delay
mechanism.
********************************************************************/
long IRCParse_ErrUnavailResource(char *strin, char **prefix, char **nick, char **nickorchannel);

/********************************************************************
RPL_AWAY 301

These replies are used with the AWAY strin (if
allowed).  RPL_AWAY is sent to any client sending a
PRIVMSG to a client which is away.  RPL_AWAY is only
sent by the server to which the client is connected.
Replies RPL_UNAWAY and RPL_NOWAWAY are sent when the
client removes and sets an AWAY message.
********************************************************************/
long IRCParse_RplAway(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
ERR_NOSUCHNICK 401

Used to indicate the nickname parameter supplied to a
strin is currently unused.
********************************************************************/
long IRCParse_ErrNoSuchNick(char *strin, char **prefix, char **nick, char **nickname, char **msg);

/********************************************************************
ERR_NOPRIVILEGES 481

Any strin requiring operator privileges to operate
MUST return this error to indicate the attempt was
unsuccessful.
********************************************************************/
long IRCParse_ErrNoPrivileges(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
ERR_NORECIPIENT 411

Returned when no recipient is given with a strin 
********************************************************************/
long IRCParse_ErrNoRecipient(char *strin, char **prefix, char **nick, char **errstring, char **msg);

/********************************************************************
RPL_WELCOME 001

Welcome to the Internet Relay Network
********************************************************************/
long IRCParse_RplWellcome(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
RPL_CREATED 003

Creation date
********************************************************************/
long IRCParse_RplCreated(char *strin, char **prefix, char **nick, char **timedate, char **msg);

/********************************************************************
RPL_BOUNCE 005

Sent by the server to a user to suggest an alternative
server.  This is often used when the connection is
refused because the server is already full.
********************************************************************/
long IRCParse_RplBounce(char *strin, char **prefix, char **nick, char **servername, int *port, char **msg);

/********************************************************************
RPL_ISUPPORT 005

Sent by the server communicating supported values (Non RFC command)
********************************************************************/
long IRCParse_RplISupport(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
RPL_TRYAGAIN 263

When a server drops a strin without processing it,
it MUST use the reply RPL_TRYAGAIN to inform the
originating client.
********************************************************************/
long IRCParse_RplTryAgain(char *strin, char **prefix, char **nick, char **errstring, char **msg);

/********************************************************************
ERR_UNKNOWNCOMMAND 421

Returned to a registered client to indicate that the
strin sent is unknown by the server.
********************************************************************/
long IRCParse_ErrUnKnownCommand(char *strin, char **prefix, char **nick, char **errstring, char **msg);

/********************************************************************
ERR_NOADMININFO 423

Returned by a server in response to an ADMIN message
when there is an error in finding the appropriate
information.
********************************************************************/
long IRCParse_ErrNoAdminInfo(char *strin, char **prefix, char **nick, char **server, char **msg);

/********************************************************************
ERR_NOTREGISTERED 451

Returned by the server to indicate that the client
MUST be registered before the server will allow it
to be parsed in detail.
********************************************************************/
long IRCParse_ErrNotRegistered(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
ERR_NOPERMFORHOST 463

Returned to a client which attempts to register with
a server which does not been setup to allow
connections from the host the attempted connection
is tried.
********************************************************************/
long IRCParse_ErrNoPermForHost(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
ERR_YOUREBANNEDCREEP 465

Returned after an attempt to connect and register
yourself with a server which has been setup to
explicitly deny connections to you.
********************************************************************/
long IRCParse_ErrYoureBannedCreep(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
ERR_YOUWILLBEBANNED 466

Sent by a server to a user to inform that access to the
server will soon be denied.
********************************************************************/
long IRCParse_ErrYouWillBeBanned(char *strin, char **prefix, char **nick);

/********************************************************************
ERR_BANLISTFULL 478

Returned when a channel access list (i.e. ban list etc) is full and
cannot be added to 
********************************************************************/
long IRCParse_ErrBanListFull(char *strin, char **prefix, char **nick, char **channel, char **character, char **msg);

/********************************************************************
ERR_UNIQOPPRIVSNEEDED 485

Any mode requiring 'channel creator' privileges returns this error
if the client is attempting to use it while not a channel creator
on the given channel 
********************************************************************/
long IRCParse_ErrUniqOPrivsNeeded(char *strin, char **prefix, char **nick, char **msg);






/********************************************************************
ERR_BADMASK 415

412 - 415 are returned by PRIVMSG to indicate that
the message wasn't delivered for some reason.
ERR_NOTOPLEVEL and ERR_WILDTOPLEVEL are errors that
are returned when an invalid use of
PRIVMSG $<server>" or "PRIVMSG #<host>" is attempted.
********************************************************************/
long IRCParse_ErrBadMask(char *strin, char **prefix, char **nick, char **mask, char **msg);

/********************************************************************
ERR_CANNOTSENDTOCHAN 404

Sent to a user who is either (a) not on a channel
which is mode +n or (b) not a chanop (or mode +v) on
a channel which has mode +m set or where the user is
banned and is trying to send a PRIVMSG message to
that channel.
********************************************************************/
long IRCParse_ErrCanNotSendToChan(char *strin, char **prefix, char **nick, char **channel, char **msg);

/********************************************************************
ERR_NOTEXTTOSEND 412

412 - 415 are returned by PRIVMSG to indicate that
the message wasn't delivered for some reason.
ERR_NOTOPLEVEL and ERR_WILDTOPLEVEL are errors that
are returned when an invalid use of
PRIVMSG $<server>" or "PRIVMSG #<host>" is attempted.
********************************************************************/
long IRCParse_ErrNoTextToSend(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
ERR_NOTOPLEVEL 413

412 - 415 are returned by PRIVMSG to indicate that
the message wasn't delivered for some reason.
ERR_NOTOPLEVEL and ERR_WILDTOPLEVEL are errors that
are returned when an invalid use of
PRIVMSG $<server>" or "PRIVMSG #<host>" is attempted.
********************************************************************/
long IRCParse_ErrNoTopLevel(char *strin, char **prefix, char **nick, char **mask, char **msg);

/********************************************************************
ERR_TOOMANYTARGETS 407

-Returned to a client which is attempting to send a
PRIVMSG/NOTICE using the user@host destination format
and for a user@host which has several occurrences.

- Returned to a client which trying to send a
PRIVMSG/NOTICE to too many recipients.

- Returned to a client which is attempting to JOIN a safe
channel using the shortname when there are more than one
such channel.
********************************************************************/
long IRCParse_ErrTooManyTargets(char *strin, char **prefix, char **nick, char **target, char **msg);

/********************************************************************
ERR_WILDTOPLEVEL 414

412 - 415 are returned by PRIVMSG to indicate that
the message wasn't delivered for some reason.
ERR_NOTOPLEVEL and ERR_WILDTOPLEVEL are errors that
are returned when an invalid use of
PRIVMSG $<server>" or "PRIVMSG #<host>" is attempted.
********************************************************************/
long IRCParse_ErrWildTopLevel(char *strin, char **prefix, char **nick, char **mask, char **msg);








/********************************************************************
ERR_CANTKILLSERVER 483

Returned by KILL to anyone who tries to kill a server 
********************************************************************/
long IRCParse_ErrCantKillServer(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
ERR_NOORIGIN 409

PING or PONG message missing the originator parameter which is
required since these strins must work without valid prefixes 
********************************************************************/
long IRCParse_ErrNoOrigin(char *strin, char **prefix, char **nick, char **msg);












/********************************************************************
RPL_ENDOFUSERS 394

Termination of an RPL_USERS list 
********************************************************************/
long IRCParse_RplEndOfUsers(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
ERR_FILEERROR 424

Generic error message used to report a failed file
operation during the processing of a message.
********************************************************************/
long IRCParse_ErrFileError(char *strin, char **prefix, char **nick, char **fileerror, char **file, char **msg);

/********************************************************************
RPL_ISON 303

Reply format used by ISON to list replies to the
query list
********************************************************************/
long IRCParse_RplIson(char *strin, char **prefix, char **nick, char **nicklist);

/********************************************************************
ERR_NOLOGIN 444

Returned by the summon after a SUMMON strin for a
user was unable to be performed since they were not
logged in.
********************************************************************/
long IRCParse_ErrNoLogin(char *strin, char **prefix, char **nick, char **user);

/********************************************************************
RPL_NOUSERS 395

If the USERS message is handled by a server, the
replies RPL_USERSTART, RPL_USERS, RPL_ENDOFUSERS and
RPL_NOUSERS are used.  RPL_USERSSTART MUST be sent
first, following by either a sequence of RPL_USERS
or a single RPL_NOUSER.  Following this is
RPL_ENDOFUSERS.
********************************************************************/
long IRCParse_RplNoUsers(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
RPL_NOWAWAY 306

These replies are used with the AWAY strin (if
allowed).  RPL_AWAY is sent to any client sending a
PRIVMSG to a client which is away.  RPL_AWAY is only
sent by the server to which the client is connected.
Replies RPL_UNAWAY and RPL_NOWAWAY are sent when the
client removes and sets an AWAY message.
********************************************************************/
long IRCParse_RplNoAway(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
RPL_REHASHING 382

If the REHASH option is used and an operator sends
a REHASH message, an RPL_REHASHING is sent back to
the operator.
********************************************************************/
long IRCParse_RplRehashing(char *strin, char **prefix, char **nick, char **configfile, char **msg);

/********************************************************************
ERR_SUMMONDISABLED 445

Returned as a response to the SUMMON strin.  MUST be
returned by any server which doesn't implement it.
********************************************************************/
long IRCParse_ErrSummonDisabled(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
long RPL_SUMMONING 342

Returned by a server answering a SUMMON message to
           indicate that it is summoning that user.
********************************************************************/
long IRCParse_RplSummoning(char *strin, char **prefix, char **nick, char **user, char **msg);

/********************************************************************
RPL_UNAWAY 305

These replies are used with the AWAY strin (if
allowed).  RPL_AWAY is sent to any client sending a
PRIVMSG to a client which is away.  RPL_AWAY is only
sent by the server to which the client is connected.
Replies RPL_UNAWAY and RPL_NOWAWAY are sent when the
client removes and sets an AWAY message.
********************************************************************/
long IRCParse_RplUnaway(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
RPL_USERHOST 302

Reply format used by USERHOST to list replies to
the query list.  The reply string is composed as
follows:

reply = nickname [ "*" ] "=" ( "+" / "-" ) hostname

The '*' indicates whether the client has registered
as an Operator.  The '-' or '+' characters represent
whether the client has set an AWAY message or not
respectively.
********************************************************************/
long IRCParse_RplUserHost(char *strin, char **prefix, char **nick, char **replylist);

/********************************************************************
RPL_USERS 393

If the USERS message is handled by a server, the
replies RPL_USERSTART, RPL_USERS, RPL_ENDOFUSERS and
RPL_NOUSERS are used.  RPL_USERSSTART MUST be sent
first, following by either a sequence of RPL_USERS
or a single RPL_NOUSER.  Following this is
RPL_ENDOFUSERS.
********************************************************************/
long IRCParse_RplUsers(char *strin, char **prefix, char **nick, char **username, char **ttyline, char **hostname);

/********************************************************************
ERR_USERSDISABLED 446

Returned as a response to the USERS strin.  MUST be
returned by any server which does not implement it.
********************************************************************/
long IRCParse_ErrUsersDisabled(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
RPL_USERSSTART 392

Start of an RPL_USERS list
********************************************************************/
long IRCParse_RplUsersStart(char *strin, char **prefix, char **nick, char **userid, char **terminal, char **host);








/********************************************************************
RPL_ADMINME 256

When replying to an ADMIN message, a server
is expected to use replies RPL_ADMINME
through to RPL_ADMINEMAIL and provide a text
message with each.  For RPL_ADMINLOC1 a
description of what city, state and country
the server is in is expected, followed by
details of the institution (RPL_ADMINLOC2)
and finally the administrative contact for the
server (an email address here is REQUIRED)
in RPL_ADMINEMAIL.
********************************************************************/
long IRCParse_RplAdminMe(char *strin, char **prefix, char **nick, char **server, char **admininfo);

/********************************************************************
RPL_ADMINLOC1 257

When replying to an ADMIN message, a server
is expected to use replies RPL_ADMINME
through to RPL_ADMINEMAIL and provide a text
message with each.  For RPL_ADMINLOC1 a
description of what city, state and country
the server is in is expected, followed by
details of the institution (RPL_ADMINLOC2)
and finally the administrative contact for the
server (an email address here is REQUIRED)
in RPL_ADMINEMAIL.
********************************************************************/
long IRCParse_RplAdminLoc1(char *strin, char **prefix, char **nick, char **admininfo);

/********************************************************************
RPL_ADMINLOC2 258

When replying to an ADMIN message, a server
is expected to use replies RPL_ADMINME
through to RPL_ADMINEMAIL and provide a text
message with each.  For RPL_ADMINLOC1 a
description of what city, state and country
the server is in is expected, followed by
details of the institution (RPL_ADMINLOC2)
and finally the administrative contact for the
server (an email address here is REQUIRED)
in RPL_ADMINEMAIL.
********************************************************************/
long IRCParse_RplAdminLoc2(char *strin, char **prefix, char **nick, char **admininfo);

/********************************************************************
RPL_ADMINEMAIL 259

When replying to an ADMIN message, a server
is expected to use replies RPL_ADMINME
through to RPL_ADMINEMAIL and provide a text
message with each.  For RPL_ADMINLOC1 a
description of what city, state and country
the server is in is expected, followed by
details of the institution (RPL_ADMINLOC2)
and finally the administrative contact for the
server (an email address here is REQUIRED)
in RPL_ADMINEMAIL.
********************************************************************/
long IRCParse_RplAdmineMail(char *strin, char **prefix, char **nick, char **admininfo);

/********************************************************************
RPL_INFO 371

A server responding to an INFO message is required to
send all its 'info' in a series of RPL_INFO messages
with a RPL_ENDOFINFO reply to indicate the end of the
replies
********************************************************************/
long IRCParse_RplInfo(char *strin, char **prefix, char **nick, char **info);

/********************************************************************
RPL_ENDOFLINKS 365

In replying to the LINKS message, a server MUST send
replies back using the RPL_LINKS numeric and mark the
end of the list using an RPL_ENDOFLINKS reply.
********************************************************************/
long IRCParse_RplEndOfLinks(char *strin, char **prefix, char **nick, char **mask, char **msg);

/********************************************************************
RPL_ENDOFINFO 374

A server responding to an INFO message is required to
send all its 'info' in a series of RPL_INFO messages
with a RPL_ENDOFINFO reply to indicate the end of the
replies
********************************************************************/
long IRCParse_RplEndOfInfo(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
RPL_ENDOFMOTD 376

When responding to the MOTD message and the MOTD file
is found, the file is displayed line by line, with
each line no longer than 80 characters, using
********************************************************************/
long IRCParse_RplEndOfMotd(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
RPL_ENDOFSTATS 219

End of RPL_STATS* list. 
********************************************************************/
long IRCParse_RplEndOfStats(char *strin, char **prefix, char **nick, char **query, char **info);

/********************************************************************
RPL_LINKS 364

In replying to the LINKS message, a server MUST send
replies back using the RPL_LINKS numeric and mark the
end of the list using an RPL_ENDOFLINKS reply.
********************************************************************/
long IRCParse_RplLinks(char *strin, char **prefix, char **nick, char **mask, char **server, char **info);

/********************************************************************
RPL_LUSERCHANNELS 254

In processing an LUSERS message, the server
sends a set of replies from RPL_LUSERCLIENT,
RPL_LUSEROP, RPL_USERUNKNOWN,
RPL_LUSERCHANNELS and RPL_LUSERME.  When
replying, a server MUST send back
RPL_LUSERCLIENT and RPL_LUSERME.  The other
replies are only sent back if a non-zero count
is found for them.
********************************************************************/
long IRCParse_RplLuserChannels(char *strin, char **prefix, char **nick, int *nchannels, char **msg);

/********************************************************************
RPL_LUSERCLIENT 251

In processing an LUSERS message, the server
sends a set of replies from RPL_LUSERCLIENT,
RPL_LUSEROP, RPL_USERUNKNOWN,
RPL_LUSERCHANNELS and RPL_LUSERME.  When
replying, a server MUST send back
RPL_LUSERCLIENT and RPL_LUSERME.  The other
replies are only sent back if a non-zero count
is found for them.
********************************************************************/
long IRCParse_RplLuserClient(char *strin, char **prefix, char **nick, char **msg, int *nusers, int *ninvisibles, int *nservers);

/********************************************************************
RPL_LUSERME 255

In processing an LUSERS message, the server
sends a set of replies from RPL_LUSERCLIENT,
RPL_LUSEROP, RPL_USERUNKNOWN,
RPL_LUSERCHANNELS and RPL_LUSERME.  When
replying, a server MUST send back
RPL_LUSERCLIENT and RPL_LUSERME.  The other
replies are only sent back if a non-zero count
is found for them.
********************************************************************/
long IRCParse_RplLuserMe(char *strin, char **prefix, char **nick, char **msg, int *nclients, int *nservers);

/********************************************************************
RPL_LUSEROP 252

In processing an LUSERS message, the server
sends a set of replies from RPL_LUSERCLIENT,
RPL_LUSEROP, RPL_USERUNKNOWN,
RPL_LUSERCHANNELS and RPL_LUSERME.  When
replying, a server MUST send back
RPL_LUSERCLIENT and RPL_LUSERME.  The other
replies are only sent back if a non-zero count
is found for them.
********************************************************************/
long IRCParse_RplLuserOp(char *strin, char **prefix, char **nick, int *nops, char **msg);

/********************************************************************
RPL_LUSERUNKOWN 253

In processing an LUSERS message, the server
sends a set of replies from RPL_LUSERCLIENT,
RPL_LUSEROP, RPL_USERUNKNOWN,
RPL_LUSERCHANNELS and RPL_LUSERME.  When
replying, a server MUST send back
RPL_LUSERCLIENT and RPL_LUSERME.  The other
replies are only sent back if a non-zero count
is found for them.
********************************************************************/
long IRCParse_RplLuserUnknown(char *strin, char **prefix, char **nick, int *unknownconn, char **msg);

/********************************************************************
RPL_MOTD 372

When responding to the MOTD message and the MOTD file
is found, the file is displayed line by line, with
each line no longer than 80 characters, using
RPL_MOTD format replies.  These MUST be surrounded
by a RPL_MOTDSTART (before the RPL_MOTDs) and an
RPL_ENDOFMOTD (after)
********************************************************************/
long IRCParse_RplMotd(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
RPL_MOTDSTART 375

When responding to the MOTD message and the MOTD file
is found, the file is displayed line by line, with
each line no longer than 80 characters, using
RPL_MOTD format replies.  These MUST be surrounded
by a RPL_MOTDSTART (before the RPL_MOTDs) and an
RPL_ENDOFMOTD (after).
********************************************************************/
long IRCParse_RplMotdStart(char *strin, char **prefix, char **nick, char **msg, char **server);

/********************************************************************
ERR_NOMOTD 422

Server's MOTD file could not be opened by the server
********************************************************************/
long IRCParse_ErrNoMotd(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
RPL_STATSCOMMANDS 212

Reports statistics on strins
********************************************************************/
long IRCParse_RplStatsCommands(char *strin, char **prefix, char **nick, char **commtype, int *count, int *bytecount, int *remotecount);

/********************************************************************
RPL_STATSLINKINFO 211

Reports statistics on a connection.  <linkname>
identifies the particular connection, <sendq> is
the amount of data that is queued and waiting to be
sent <sent messages> the number of messages sent,
and <sent Kbytes> the amount of data sent, in
Kbytes. <received messages> and <received Kbytes>
are the equivalent of <sent messages> and <sent
Kbytes> for received data, respectively.  <time
open> indicates how long ago the connection was
opened, in seconds.
********************************************************************/
long IRCParse_RplStatsLinkInfo(char *strin, char **prefix, char **nick, char **linkname, int *sendq, int *sentmessages, int *sentKB, int *recmessages, int *recKB, int *timeopen);

/********************************************************************
RPL_STATSOLINE 243

Reports the allowed hosts from where user may become IRC
operators O <hostmask> * <name>
********************************************************************/
long IRCParse_RplStatsOLine(char *strin, char **prefix, char **nick, char **hostmask, char **name);

/********************************************************************
RPL_STATSUPTIME 342

Returned by a server answering a SUMMON message to
indicate that it is summoning that user.
********************************************************************/
long IRCParse_RplStatsUptime(char *strin, char **prefix, char **nick, char **msg, int *days, char **tod);

/********************************************************************
RPL_TIME 391

When replying to the TIME message, a server MUST send
the reply using the RPL_TIME format above.  The string
showing the time need only contain the correct day and
time there.  There is no further requirement for the
time string.
********************************************************************/
long IRCParse_RplTime(char *strin, char **prefix, char **nick, char **server, char **msg, char **m, char **dom, char **y, char **t);

/********************************************************************
RPL_TRACECLASS 209

The RPL_TRACE* are all returned by the server in
response to the TRACE message.  How many are
returned is dependent on the TRACE message and
whether it was sent by an operator or not.  There
is no predefined order for which occurs first.
Replies RPL_TRACEUNKNOWN, RPL_TRACECONNECTING and
RPL_TRACEHANDSHAKE are all used for connections
which have not been fully established and are either
unknown, still attempting to connect or in the
process of completing the 'server handshake'.
RPL_TRACELINK is sent by any server which handles
a TRACE message and has to pass it on to another
server.  The list of RPL_TRACELINKs sent in
response to a TRACE strin traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRCParse_RplTraceClass(char *strin, char **prefix, char **nick, char **class, int *count);

/********************************************************************
RPL_TRACECONNECT 210

The RPL_TRACE* are all returned by the server in
response to the TRACE message.  How many are
returned is dependent on the TRACE message and
whether it was sent by an operator or not.  There
is no predefined order for which occurs first.
Replies RPL_TRACEUNKNOWN, RPL_TRACECONNECTING and
RPL_TRACEHANDSHAKE are all used for connections
which have not been fully established and are either
unknown, still attempting to connect or in the
process of completing the 'server handshake'.
RPL_TRACELINK is sent by any server which handles
a TRACE message and has to pass it on to another
server.  The list of RPL_TRACELINKs sent in
response to a TRACE strin traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRCParse_RplTraceConnect(char *strin, char **prefix, char **nick);

/********************************************************************
RPL_TRACECONNECTING 201

The RPL_TRACE* are all returned by the server in
response to the TRACE message.  How many are
returned is dependent on the TRACE message and
whether it was sent by an operator or not.  There
is no predefined order for which occurs first.
Replies RPL_TRACEUNKNOWN, RPL_TRACECONNECTING and
RPL_TRACEHANDSHAKE are all used for connections
which have not been fully established and are either
unknown, still attempting to connect or in the
process of completing the 'server handshake'.
RPL_TRACELINK is sent by any server which handles
a TRACE message and has to pass it on to another
server.  The list of RPL_TRACELINKs sent in
response to a TRACE strin traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRCParse_RplTraceConnecting(char *strin, char **prefix, char **nick, char **class, char **server);

/********************************************************************
RPL_TRACEHANDSHAKE 202

The RPL_TRACE* are all returned by the server in
response to the TRACE message.  How many are
returned is dependent on the TRACE message and
whether it was sent by an operator or not.  There
is no predefined order for which occurs first.
Replies RPL_TRACEUNKNOWN, RPL_TRACECONNECTING and
RPL_TRACEHANDSHAKE are all used for connections
which have not been fully established and are either
unknown, still attempting to connect or in the
process of completing the 'server handshake'.
RPL_TRACELINK is sent by any server which handles
a TRACE message and has to pass it on to another
server.  The list of RPL_TRACELINKs sent in
response to a TRACE strin traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRCParse_RplTraceHandshake(char *strin, char **prefix, char **nick, char **class, char **server);

/********************************************************************
RPL_TRACELINK   200

The RPL_TRACE* are all returned by the server in
response to the TRACE message.  How many are
returned is dependent on the TRACE message and
whether it was sent by an operator or not.  There
is no predefined order for which occurs first.
Replies RPL_TRACEUNKNOWN, RPL_TRACECONNECTING and
RPL_TRACEHANDSHAKE are all used for connections
which have not been fully established and are either
unknown, still attempting to connect or in the
process of completing the 'server handshake'.
RPL_TRACELINK is sent by any server which handles
a TRACE message and has to pass it on to another
server.  The list of RPL_TRACELINKs sent in
response to a TRACE strin traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRCParse_RplTraceLink(char *strin, char **prefix, char **nick, int *version, int *debuglevel, char **dest,
			char **nextserver, int *protocolversion, int *linkuptime, int *backstreamsendq, int *upstreamsendq);

/********************************************************************
RPL_TRACENEWTYPE 208

The RPL_TRACE* are all returned by the server in
response to the TRACE message.  How many are
returned is dependent on the TRACE message and
whether it was sent by an operator or not.  There
is no predefined order for which occurs first.
Replies RPL_TRACEUNKNOWN, RPL_TRACECONNECTING and
RPL_TRACEHANDSHAKE are all used for connections
which have not been fully established and are either
unknown, still attempting to connect or in the
process of completing the 'server handshake'.
RPL_TRACELINK is sent by any server which handles
a TRACE message and has to pass it on to another
server.  The list of RPL_TRACELINKs sent in
response to a TRACE strin traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRCParse_RplTraceNewType(char *strin, char **prefix, char **nick, char **newtype, char **clientname);

/********************************************************************
RPL_TRACEOPERATOR 204

The RPL_TRACE* are all returned by the server in
response to the TRACE message.  How many are
returned is dependent on the TRACE message and
whether it was sent by an operator or not.  There
is no predefined order for which occurs first.
Replies RPL_TRACEUNKNOWN, RPL_TRACECONNECTING and
RPL_TRACEHANDSHAKE are all used for connections
which have not been fully established and are either
unknown, still attempting to connect or in the
process of completing the 'server handshake'.
RPL_TRACELINK is sent by any server which handles
a TRACE message and has to pass it on to another
server.  The list of RPL_TRACELINKs sent in
response to a TRACE strin traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRCParse_RplTraceOperator(char *strin, char **prefix, char **nick, char **class, char **nick2);

/********************************************************************
RPL_TRACESERVER 206

The RPL_TRACE* are all returned by the server in
response to the TRACE message.  How many are
returned is dependent on the TRACE message and
whether it was sent by an operator or not.  There
is no predefined order for which occurs first.
Replies RPL_TRACEUNKNOWN, RPL_TRACECONNECTING and
RPL_TRACEHANDSHAKE are all used for connections
which have not been fully established and are either
unknown, still attempting to connect or in the
process of completing the 'server handshake'.
RPL_TRACELINK is sent by any server which handles
a TRACE message and has to pass it on to another
server.  The list of RPL_TRACELINKs sent in
response to a TRACE strin traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRCParse_RplTraceServer(char *strin, char **prefix, char **nick, char **class, int *nlinks, int *nlinkc,
		   char **server, char **complexuser, int *protocolversion);

/********************************************************************
RPL_TRACESERVICE 207

The RPL_TRACE* are all returned by the server in
response to the TRACE message.  How many are
returned is dependent on the TRACE message and
whether it was sent by an operator or not.  There
is no predefined order for which occurs first.
Replies RPL_TRACEUNKNOWN, RPL_TRACECONNECTING and
RPL_TRACEHANDSHAKE are all used for connections
which have not been fully established and are either
unknown, still attempting to connect or in the
process of completing the 'server handshake'.
RPL_TRACELINK is sent by any server which handles
a TRACE message and has to pass it on to another
server.  The list of RPL_TRACELINKs sent in
response to a TRACE strin traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRCParse_RplTraceService(char *strin, char **prefix, char **nick, char **class, char **name, char **type, char **activetype);

/********************************************************************
RPL_TRACEUSER 205

The RPL_TRACE* are all returned by the server in
response to the TRACE message.  How many are
returned is dependent on the TRACE message and
whether it was sent by an operator or not.  There
is no predefined order for which occurs first.
Replies RPL_TRACEUNKNOWN, RPL_TRACECONNECTING and
RPL_TRACEHANDSHAKE are all used for connections
which have not been fully established and are either
unknown, still attempting to connect or in the
process of completing the 'server handshake'.
RPL_TRACELINK is sent by any server which handles
a TRACE message and has to pass it on to another
server.  The list of RPL_TRACELINKs sent in
response to a TRACE strin traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRCParse_RplTraceUser(char *strin, char **prefix, char **nick, char **class, char **nick2);

/********************************************************************
RPL_TRACEUNKNOWN 203

The RPL_TRACE* are all returned by the server in
response to the TRACE message.  How many are
returned is dependent on the TRACE message and
whether it was sent by an operator or not.  There
is no predefined order for which occurs first.
Replies RPL_TRACEUNKNOWN, RPL_TRACECONNECTING and
RPL_TRACEHANDSHAKE are all used for connections
which have not been fully established and are either
unknown, still attempting to connect or in the
process of completing the 'server handshake'.
RPL_TRACELINK is sent by any server which handles
a TRACE message and has to pass it on to another
server.  The list of RPL_TRACELINKs sent in
response to a TRACE strin traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRCParse_RplTraceUnknown(char *strin, char **prefix, char **nick, char **class, char **ip);

/********************************************************************
RPL_TRACELOG 261

The RPL_TRACE* are all returned by the server in
response to the TRACE message.  How many are
returned is dependent on the TRACE message and
whether it was sent by an operator or not.  There
is no predefined order for which occurs first.
Replies RPL_TRACEUNKNOWN, RPL_TRACECONNECTING and
RPL_TRACEHANDSHAKE are all used for connections
which have not been fully established and are either
unknown, still attempting to connect or in the
process of completing the 'server handshake'.
RPL_TRACELINK is sent by any server which handles
a TRACE message and has to pass it on to another
server.  The list of RPL_TRACELINKs sent in
response to a TRACE strin traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRCParse_RplTraceLog(char *strin, char **prefix, char **nick, char **logfile, int *debuglevel);

/********************************************************************
RPL_TRACEEND 262

The RPL_TRACE* are all returned by the server in
response to the TRACE message.  How many are
returned is dependent on the TRACE message and
whether it was sent by an operator or not.  There
is no predefined order for which occurs first.
Replies RPL_TRACEUNKNOWN, RPL_TRACECONNECTING and
RPL_TRACEHANDSHAKE are all used for connections
which have not been fully established and are either
unknown, still attempting to connect or in the
process of completing the 'server handshake'.
RPL_TRACELINK is sent by any server which handles
a TRACE message and has to pass it on to another
server.  The list of RPL_TRACELINKs sent in
response to a TRACE strin traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRCParse_RplTraceEnd(char *strin, char **prefix, char **nick, char **servername, int *version, int *debuglevel, char **msg);

/********************************************************************
RPL_VERSION 351

Reply by the server showing its version details.
The <version> is the version of the software being
used (including any patchlevel revisions) and the
debuglevel> is used to indicate if the server is
running in "debug mode".

The "comments" field may contain any comments about
the version or further version details.
********************************************************************/
long IRCParse_RplVersion(char *strin, char **prefix, char **nick, int *version, int *debuglevel, char **server, char **msg);






/********************************************************************
ERR_NOSUCHSERVICE 408

Returned to a client which is attempting to send a SQUERY
to a service which does not exist.
********************************************************************/
long IRCParse_ErrNoSuchService(char *strin, char **prefix, char **nick, char **servicename, char **msg);

/********************************************************************
RPL_SERVLIST 234

When listing services in reply to a SERVLIST message,
a server is required to send the list back using the
RPL_SERVLIST and RPL_SERVLISTEND messages.  A separate
RPL_SERVLIST is sent for each service.  After the
services have been listed (or if none present) a
RPL_SERVLISTEND MUST be sent.
********************************************************************/
long IRCParse_RplServList(char *strin, char **prefix, char **nick, char **name, char **server, char **mask, char **type, int *hopcount, char **info);

/********************************************************************
RPL_SERVLISTEND 235

When listing services in reply to a SERVLIST message,
a server is required to send the list back using the
RPL_SERVLIST and RPL_SERVLISTEND messages.  A separate
RPL_SERVLIST is sent for each service.  After the
services have been listed (or if none present) a
RPL_SERVLISTEND MUST be sent.
              "<mask> <type> :End of service listing"
********************************************************************/
long IRCParse_RplServListEnd(char *strin, char **prefix, char **nick, char **mask, char **type, char **msg);






/********************************************************************
RPL_ENDOFWHO 315

The RPL_WHOREPLY and RPL_ENDOFWHO pair are used
to answer a WHO message.  The RPL_WHOREPLY is only
sent if there is an appropriate match to the WHO
query.  If there is a list of parameters supplied
with a WHO message, a RPL_ENDOFWHO MUST be sent
after processing each list item with <name> being
the item.
********************************************************************/
long IRCParse_RplEndOfWho(char *strin, char **prefix, char **nick, char **name, char **msg);

/********************************************************************
RPL_ENDOFWHOIS 318

Replies 311 - 313, 317 - 319 are all replies
generated in response to a WHOIS message.  Given that
there are enough parameters present, the answering
server MUST either formulate a reply out of the above
numerics (if the query nick is found) or return an
error reply.  The '*' in RPL_WHOISUSER is there as
the literal character and not as a wild card.  For
each reply set, only RPL_WHOISCHANNELS may appear
more than once (for long lists of channel names).
The '@' and '+' characters next to the channel name
indicate whether a client is a channel operator or
has been granted permission to speak on a moderated
channel.  The RPL_ENDOFWHOIS reply is used to mark
the end of processing a WHOIS message.
********************************************************************/
long IRCParse_RplEndOfWhoIs(char *strin, char **prefix, char **nick, char **name, char **msg);

/********************************************************************
RPL_ENDOFWHOWAS 369

When replying to a WHOWAS message, a server MUST use
the replies RPL_WHOWASUSER, RPL_WHOISSERVER or
ERR_WASNOSUCHNICK for each nickname in the presented
list.  At the end of all reply batches, there MUST
be RPL_ENDOFWHOWAS (even if there was only one reply
and it was an error)
********************************************************************/
long IRCParse_RplEndOfWhoWas(char *strin, char **prefix, char **nick, char **name, char **msg);

/********************************************************************
ERR_WASNOSUCHNICK 406

Returned by WHOWAS to indicate there is no history
information for that nickname.

When replying to a WHOWAS message, a server MUST use
the replies RPL_WHOWASUSER, RPL_WHOISSERVER or
ERR_WASNOSUCHNICK for each nickname in the presented
list.  At the end of all reply batches, there MUST
be RPL_ENDOFWHOWAS (even if there was only one reply
and it was an error)
********************************************************************/
long IRCParse_ErrWasNoSuchNick(char *strin, char **prefix, char **nick, char **nickname, char **msg);

/********************************************************************
RPL_WHOWASUSER 314

When replying to a WHOWAS message, a server MUST use
the replies RPL_WHOWASUSER, RPL_WHOISSERVER or
ERR_WASNOSUCHNICK for each nickname in the presented
list.  At the end of all reply batches, there MUST
be RPL_ENDOFWHOWAS (even if there was only one reply
and it was an error)
********************************************************************/
long IRCParse_RplWhoWasUser(char *strin, char **prefix, char **nick, char **nick2, char **name, char **host, char **realname);

/********************************************************************
RPL_WHOISUSER 311

Replies 311 - 313, 317 - 319 are all replies
generated in response to a WHOIS message.  Given that
there are enough parameters present, the answering
server MUST either formulate a reply out of the above
numerics (if the query nick is found) or return an
error reply.  The '*' in RPL_WHOISUSER is there as
the literal character and not as a wild card.  For
each reply set, only RPL_WHOISCHANNELS may appear
more than once (for long lists of channel names).
The '@' and '+' characters next to the channel name
indicate whether a client is a channel operator or
has been granted permission to speak on a moderated
channel.  The RPL_ENDOFWHOIS reply is used to mark
the end of processing a WHOIS message.
********************************************************************/
long IRCParse_RplWhoIsUser(char *strin, char **prefix, char **nick, char **nick2, char **name, char **host, char **realname);

/********************************************************************
RPL_WHOISCHANNELS 319

Replies 311 - 313, 317 - 319 are all replies
generated in response to a WHOIS message.  Given that
there are enough parameters present, the answering
server MUST either formulate a reply out of the above
numerics (if the query nick is found) or return an
error reply.  The '*' in RPL_WHOISUSER is there as
the literal character and not as a wild card.  For
each reply set, only RPL_WHOISCHANNELS may appear
more than once (for long lists of channel names).
The '@' and '+' characters next to the channel name
indicate whether a client is a channel operator or
has been granted permission to speak on a moderated
channel.  The RPL_ENDOFWHOIS reply is used to mark
the end of processing a WHOIS message.
********************************************************************/
long IRCParse_RplWhoIsChannels(char *strin, char **prefix, char **nick, char **channelstr);

/********************************************************************
RPL_WHOISOPERATOR 313

Replies 311 - 313, 317 - 319 are all replies
generated in response to a WHOIS message.  Given that
there are enough parameters present, the answering
server MUST either formulate a reply out of the above
numerics (if the query nick is found) or return an
error reply.  The '*' in RPL_WHOISUSER is there as
the literal character and not as a wild card.  For
each reply set, only RPL_WHOISCHANNELS may appear
more than once (for long lists of channel names).
The '@' and '+' characters next to the channel name
indicate whether a client is a channel operator or
has been granted permission to speak on a moderated
channel.  The RPL_ENDOFWHOIS reply is used to mark
the end of processing a WHOIS message.
********************************************************************/
long IRCParse_RplWhoIsOperator(char *strin, char **prefix, char **nick, char **nick2, char **msg);

/********************************************************************
RPL_WHOISSERVER 312

Replies 311 - 313, 317 - 319 are all replies
generated in response to a WHOIS message.  Given that
there are enough parameters present, the answering
server MUST either formulate a reply out of the above
numerics (if the query nick is found) or return an
error reply.  The '*' in RPL_WHOISUSER is there as
the literal character and not as a wild card.  For
each reply set, only RPL_WHOISCHANNELS may appear
more than once (for long lists of channel names).
The '@' and '+' characters next to the channel name
indicate whether a client is a channel operator or
has been granted permission to speak on a moderated
channel.  The RPL_ENDOFWHOIS reply is used to mark
the end of processing a WHOIS message.

When replying to a WHOWAS message, a server MUST use
the replies RPL_WHOWASUSER, RPL_WHOISSERVER or
ERR_WASNOSUCHNICK for each nickname in the presented
list.  At the end of all reply batches, there MUST
be RPL_ENDOFWHOWAS (even if there was only one reply
and it was an error)
<nick> <server> :<server_info> 
********************************************************************/
long IRCParse_RplWhoIsServer(char *strin, char **prefix, char **nick, char **nick2, char **server, char **serverinfo);

/********************************************************************
RPL_WHOISIDLE 317

Replies 311 - 313, 317 - 319 are all replies
generated in response to a WHOIS message.  Given that
there are enough parameters present, the answering
server MUST either formulate a reply out of the above
numerics (if the query nick is found) or return an
error reply.  The '*' in RPL_WHOISUSER is there as
the literal character and not as a wild card.  For
each reply set, only RPL_WHOISCHANNELS may appear
more than once (for long lists of channel names).
The '@' and '+' characters next to the channel name
indicate whether a client is a channel operator or
has been granted permission to speak on a moderated
channel.  The RPL_ENDOFWHOIS reply is used to mark
the end of processing a WHOIS message.
********************************************************************/
long IRCParse_RplWhoIsIdle(char *strin, char **prefix, char **nick, char **nick2, int *sec_idle, int *ref, char **msg);

/********************************************************************
RPL_WHOREPLY 352

The RPL_WHOREPLY and RPL_ENDOFWHO pair are used
to answer a WHO message.  The RPL_WHOREPLY is only
sent if there is an appropriate match to the WHO
query.  If there is a list of parameters supplied
with a WHO message, a RPL_ENDOFWHO MUST be sent
after processing each list item with <name> being
the item.
********************************************************************/
long IRCParse_RplWhoReply(char *strin, char **prefix, char **nick, char **channel, char **user, char **host, char **server, char **nick2, char **type, char **msg, int *hopcount, char **realname);











/********************************************************************
ERR_ALREADYREGISTRED

Returned by the server to any link which tries to
change part of the registered details (such as
password or user details from second USER message).
********************************************************************/
long IRCParse_ErrAlredyRegistred(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
ERR_ERRONEUSNICKNAME

Returned after receiving a NICK message which contains
characters which do not fall in the defined set.
********************************************************************/
long IRCParse_ErrErroneusNickName(char *strin, char **prefix, char **nick, char **erroneusnick, char **msg);

/********************************************************************
ERR_ERRONEUSNICKNAME

Returned when a NICK message is processed that results
in an attempt to change to a currently existing
nickname.
********************************************************************/
long IRCParse_ErrNickNameInUse(char *strin, char **prefix, char **nick, char **erroneusnick, char **msg);

/********************************************************************
ERR_NICKCOLLISION

Returned by a server to a client when it detects a
nickname collision (registered of a NICK that
already exists by another server).
********************************************************************/
long IRCParse_ErrNickCollision(char *strin, char **prefix, char **nick, char **nick2, char **msg, char **complexuser);

/********************************************************************
RPL_YOUREOPER

Is sent back to a client which has
just successfully issued an OPER message and gained
operator status.
********************************************************************/
long IRCParse_RplYoureOper(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
ERR_NOOPERHOST

If a client sends an OPER message and the server has
not been configured to allow connections from the
client's host as an operator, this error MUST be
returned.
********************************************************************/
long IRCParse_ErrNoOperHost(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
RPL_UMODEIS

To answer a query about a client's own mode,
RPL_UMODEIS is sent back.
********************************************************************/
long IRCParse_RplUModeIs(char *strin, char **prefix, char **nick, char **usermodestring);

/********************************************************************
ERR_UMODEUNKNOWNFLAG

Returned by the server to indicate that a MODE
message was sent with a nickname parameter and that
the a mode flag sent was not recognized.
********************************************************************/
long IRCParse_ErrUModeUnknownFlag(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
ERR_USERSDONTMATCH

Error sent to any user trying to view or change the
user mode for a user other than themselves.
********************************************************************/
long IRCParse_ErrUsersDontMatch(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
RPL_YOURESERVICE

Sent by the server to a service upon successful
registration.
********************************************************************/
long IRCParse_RplYoureService(char *strin, char **prefix, char **nick, char **msg, char **servicename);

/********************************************************************
RPL_YOURHOST

The server sends Replies 001 to 004 to a user upon
successful registration.
********************************************************************/
long IRCParse_RplYourHost(char *strin, char **prefix, char **nick, char **msg, char **servername, char **versionname);

/********************************************************************
RPL_MYINFO

The server sends Replies 001 to 004 to a user upon
successful registration.
********************************************************************/
long IRCParse_RplMyInfo(char *strin, char **prefix, char **nick, char **servername, char **version, char **availableusermodes, char **availablechannelmodes, char **added);



long IRCParse_RplYourId (char *strin, char **prefix, char **nick, char **id, char **msg);

long IRCParse_RplCreationTime (char *strin, char **prefix, char **nick, char **channel, int *time);

long IRCParse_RplLocalUsers (char *strin, char **prefix, char **nick, char **msg, int *total, int *maximum);

long IRCParse_RplGlobalUsers (char *strin, char **prefix, char **nick, char **msg, int *total, int *maximum);

long IRCParse_RplTopicWhoTime (char *strin, char **prefix, char **nick, char **channel, char **complexuser, int *time);

long IRCParse_RplChannelUrl (char *strin, char **prefix, char **nick, char **channel, char **url);



#endif
