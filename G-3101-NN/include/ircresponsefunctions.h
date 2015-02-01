#ifndef _IRCRESPONSEFUNCTIONS_H_
#define _IRCRESPONSEFUNCTIONS_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********************************************************************
ERR_BADCHANMASK 476

The given channel mask was invalid 
********************************************************************/
long IRC_ErrBadChanMask(char *command, char *prefix, char *nick, char *channel);

/********************************************************************
ERR_BADCHANNELKEY 475

Returned when attempting to join a key-locked channel either
without a key or with the wrong key 
********************************************************************/
long IRC_ErrBadChannelKey(char *command, char *prefix, char *nick, char *channel);

/********************************************************************
RPL_BANLIST 367

A ban-list item
********************************************************************/
long IRC_RplBanList(char *command, char *prefix, char *nick, char *channel);

/********************************************************************
ERR_BANNEDFROMCHAN 474

Returned when attempting to join a channel a user is banned from 
********************************************************************/
long IRC_ErrBannedFromChan(char *command, char *prefix, char *nick, char *channel);

/********************************************************************
ERR_CHANNELISFULL 471

Returned when attempting to join a channel which is set +l and is
already full 
********************************************************************/
long IRC_ErrChannelListFull(char *command, char *prefix, char *nick, char *channel);

/********************************************************************
RPL_CHANNELMODEIS 324

Mode of channel
********************************************************************/
long IRC_RplChannelModeIs(char *command, char *prefix, char *nick, char *channel, char *mode);

/********************************************************************
ERR_CHANOPRIVSNEEDED 482

Any command requiring 'chanop' privileges (such as
MODE messages) MUST return this error if the client
making the attempt is not a chanop on the specified
channel.
********************************************************************/
long IRC_ErrChanOPrivsNeeded(char *command, char *prefix, char *nick, char *channel);

/********************************************************************
RPL_ENDOFBANLIST 368

When listing the active 'bans' for a given channel,
a server is required to send the list back using the
RPL_BANLIST and RPL_ENDOFBANLIST messages.  A separate
RPL_BANLIST is sent for each active banmask.  After the
banmasks have been listed (or if none present) a
RPL_ENDOFBANLIST MUST be sent.
********************************************************************/
long IRC_RplEndOfBanList(char *command, char *prefix, char *nick, char *channel);

/********************************************************************
RPL_ENDOFEXCEPTLIST 349

When listing the 'exception masks' for a given channel,
a server is required to send the list back using the
RPL_EXCEPTLIST and RPL_ENDOFEXCEPTLIST messages.  A
separate RPL_EXCEPTLIST is sent for each active mask.
After the masks have been listed (or if none present)
a RPL_ENDOFEXCEPTLIST MUST be sent.
********************************************************************/
long IRC_RplEndOfExceptList(char *command, char *prefix, char *nick, char *channel);

/********************************************************************
RPL_ENDOFINVITELIST 347

When listing the 'invitations masks' for a given channel,
a server is required to send the list back using the
RPL_INVITELIST and RPL_ENDOFINVITELIST messages.  A
separate RPL_INVITELIST is sent for each active mask.
After the masks have been listed (or if none present) a
RPL_ENDOFINVITELIST MUST be sent.
********************************************************************/
long IRC_RplEndOfInviteList(char *command, char *prefix, char *nick, char *channel);

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
long IRC_RplEndOfNames(char *command, char *prefix, char *nick, char *channel);

/********************************************************************
RPL_EXCEPTLIST 348

When listing the 'exception masks' for a given channel,
a server is required to send the list back using the
RPL_EXCEPTLIST and RPL_ENDOFEXCEPTLIST messages.  A
separate RPL_EXCEPTLIST is sent for each active mask.
After the masks have been listed (or if none present)
a RPL_ENDOFEXCEPTLIST MUST be sent.
********************************************************************/
long IRC_RplExceptList(char *command, char *prefix, char *nick, char *channel, char *exceptionmask);

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
long IRC_RplInviteList(char *command, char *prefix, char *nick, char *channel, char *invitemask);

/********************************************************************
ERR_INVITEONLYCHAN 473

Any command requiring operator privileges to operate
MUST return this error to indicate the attempt was
unsuccessful.
********************************************************************/
long IRC_ErrInviteOnlyChan(char *command, char *prefix, char *nick, char *channel);

/********************************************************************
RPL_INVITING 341

Returned by the server to indicate that the
attempted INVITE message was successful and is
being passed onto the end client.
********************************************************************/
long IRC_RplInviting(char *command, char *prefix, char *nick, char *channel, char *nick2);

/********************************************************************
ERR_KEYSET 467

Any command requiring operator privileges to operate
MUST return this error to indicate the attempt was
unsuccessful.
********************************************************************/
long IRC_ErrKeySet(char *command, char *prefix, char *nick, char *channel);

/********************************************************************
RPL_LISTSTART 321

Obsolete.
********************************************************************/
long IRC_RplListStart(char *command, char *prefix, char *nick);

/********************************************************************
RPL_LIST 322

Replies RPL_LIST, RPL_LISTEND mark the actual replies
with data and end of the server's response to a LIST
command.  If there are no channels available to return,
only the end reply MUST be sent.
              "<channel> <# visible> :<topic>"
********************************************************************/
long IRC_RplList(char *command, char *prefix, char *nick, char *channel, char *visible, char *topic);

/********************************************************************
RPL_LISTEND 323

Replies RPL_LIST, RPL_LISTEND mark the actual replies
with data and end of the server's response to a LIST
command.  If there are no channels available to return,
only the end reply MUST be sent.
********************************************************************/
long IRC_RplListEnd(char *command, char *prefix, char *nick);

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
long IRC_RplNamReply(char *command, char *prefix, char *nick, char *name);

/********************************************************************
ERR_NOCHANMODES 477

Any command requiring operator privileges to operate
MUST return this error to indicate the attempt was
unsuccessful.
********************************************************************/
long IRC_ErrNoChanModes(char *command, char *prefix, char *nick, char *channel);

/********************************************************************
ERR_NOSUCHCHANNEL 403

Used to indicate the given channel name is invalid.
********************************************************************/
long IRC_ErrNoSuchCannel(char *command, char *prefix, char *nick, char *channelname);

/********************************************************************
ERR_NOTONCHANNEL 442

Returned by the server whenever a client tries to
perform a channel affecting command for which the
client isn't a member.
********************************************************************/
long IRC_ErrNotOnChannel(char *command, char *prefix, char *nick, char *nick2, char *channel);

/********************************************************************
RPL_NOTOPIC 331

When sending a TOPIC message to determine the
channel topic, one of two replies is sent.  If
the topic is set, RPL_TOPIC is sent back else
RPL_NOTOPIC.
********************************************************************/
long IRC_RplNoTopic(char *command, char *prefix, char *nick, char *channel, char *topic);

/********************************************************************
ERR_TOOMANYCHANNELS 405

Sent to a user when they have joined the maximum
number of allowed channels and they try to join
another channel.
********************************************************************/
long IRC_ErrTooManyChannels(char *command, char *prefix, char *nick, char *channelname);

/********************************************************************
ERR_TOOMANYMATCHES 416

Returned when too many matches have been found for a command and
the output has been truncated. An example would be the WHO command,
where by the mask '*' would match everyone on the network! Ouch!
********************************************************************/
long IRC_ErrTooManyMatches(char *command, char *prefix, char *nick, char *errcommand, char *mask, char *info);

/********************************************************************
ERR_UNKNOWNMODE 472

Any command requiring operator privileges to operate
MUST return this error to indicate the attempt was
unsuccessful.
********************************************************************/
long IRC_ErrUnknownMode(char *command, char *prefix, char *nick, char *modechar, char *channel);

/********************************************************************
ERR_USERNOTINCHANNEL 441

Returned by the server to indicate that the target
user of the command is not on the given channel.
              "<nick> <channel> :They aren't on that channel"
********************************************************************/
long IRC_ErrUserNotInChannel(char *command, char *prefix, char *nick, char *nick2, char *channel);

/********************************************************************
ERR_USERONCHANNEL 443

Returned when a client tries to invite a user to a
channel they are already on.
********************************************************************/
long IRC_ErrUserOnChannel(char *command, char *prefix, char *user, char *user2, char *channel);

/********************************************************************
RPL_UNIQOPIS 325

Unique Operator
********************************************************************/
long IRC_RplUniqOpIs(char *command, char *prefix, char *nick, char *channel, char *nickname);

/********************************************************************
RPL_TOPIC 332

When sending a TOPIC message to determine the
channel topic, one of two replies is sent.  If
the topic is set, RPL_TOPIC is sent back else
RPL_NOTOPIC.
********************************************************************/
long IRC_RplTopic(char *command, char *prefix, char *nick, char *channel, char *topic);












/********************************************************************
ERR_NEEDMOREPARAMS

Returned by the server by numerous commands to
indicate to the client that it didn't supply enough
parameters.
********************************************************************/
long IRC_ErrNeedMoreParams(char *command, char *prefix, char *nick, char *failedcommand);

/********************************************************************
ERR_NONICKNAMEGIVEN

Returned when a nickname parameter expected for a
command and isn't found.
********************************************************************/
long IRC_ErrNoNickNameGiven(char *command, char *prefix, char *nick);

/********************************************************************
ERR_NOSUCHSERVER

Used to indicate the server name given currently
does not exist.
********************************************************************/
long IRC_ErrNoSuchServer(char *command, char *prefix, char *nick, char *servername);

/********************************************************************
ERR_PASSWDMISMATCH

Returned to indicate a failed attempt at registering
a connection for which a password was required and
was either not given or incorrect.

********************************************************************/
long IRC_ErrPasswdMismatch(char *command, char *prefix, char *nick);

/********************************************************************
ERR_RESTRICTED

Sent by the server to a user upon connection to indicate
the restricted nature of the connection (user mode "+r").
********************************************************************/
long IRC_ErrRestricted(char *command, char *prefix, char *nick);

/********************************************************************
ERR_UNAVAILRESOURCE

Returned by a server to a user trying to join a channel
currently blocked by the channel delay mechanism.

Returned by a server to a user trying to change nickname
when the desired nickname is blocked by the nick delay
mechanism.
********************************************************************/
long IRC_ErrUnavailResource(char *command, char *prefix, char *nick, char *nickorchannel);

/********************************************************************
RPL_AWAY 301

These replies are used with the AWAY command (if
allowed).  RPL_AWAY is sent to any client sending a
PRIVMSG to a client which is away.  RPL_AWAY is only
sent by the server to which the client is connected.
Replies RPL_UNAWAY and RPL_NOWAWAY are sent when the
client removes and sets an AWAY message.
********************************************************************/
long IRC_RplAway(char *command, char *prefix, char *nick, char *msg);

/********************************************************************
ERR_NOSUCHNICK 401

Used to indicate the nickname parameter supplied to a
command is currently unused.
********************************************************************/
long IRC_ErrNoSuchNick(char *command, char *prefix, char *nick,char *nickname);

/********************************************************************
ERR_NOPRIVILEGES 481

Any command requiring operator privileges to operate
MUST return this error to indicate the attempt was
unsuccessful.
********************************************************************/
long IRC_ErrNoPrivileges(char *command, char *prefix, char *nick);

/********************************************************************
ERR_NORECIPIENT 411

Returned when no recipient is given with a command 
********************************************************************/
long IRC_ErrNoRecipient(char *command, char *prefix, char *nick, char *errcommand);

/********************************************************************
RPL_WELCOME 001

Welcome to the Internet Relay Network
********************************************************************/
long IRC_RplWellcome(char *command, char *prefix, char *nick1, char *nick2, char *user, char *host);

/********************************************************************
RPL_CREATED 003

Creation date
********************************************************************/
long IRC_RplCreated(char *command, char *prefix, char *nick);

/********************************************************************
RPL_BOUNCE 005

Sent by the server to a user to suggest an alternative
server.  This is often used when the connection is
refused because the server is already full.
********************************************************************/
long IRC_RplBounce(char *command, char *prefix, char *nick, char *servername, int port);

/********************************************************************
RPL_TRYAGAIN 263

When a server drops a command without processing it,
it MUST use the reply RPL_TRYAGAIN to inform the
originating client.
********************************************************************/
long IRC_RplTryAgain(char *command, char *prefix, char *nick, char *errcommand);

/********************************************************************
ERR_UNKNOWNCOMMAND 421

Returned to a registered client to indicate that the
command sent is unknown by the server.
********************************************************************/
long IRC_ErrUnKnownCommand(char *command, char *prefix, char *nick, char *errcommand);

/********************************************************************
ERR_NOADMININFO 423

Returned by a server in response to an ADMIN message
when there is an error in finding the appropriate
information.
********************************************************************/
long IRC_ErrNoAdminInfo(char *command, char *prefix, char *nick, char *server);

/********************************************************************
ERR_NOTREGISTERED 451

Returned by the server to indicate that the client
MUST be registered before the server will allow it
to be parsed in detail.
********************************************************************/
long IRC_ErrNotRegisterd(char *command, char *prefix, char *nick);

/********************************************************************
ERR_NOPERMFORHOST 463

Returned to a client which attempts to register with
a server which does not been setup to allow
connections from the host the attempted connection
is tried.
********************************************************************/
long IRC_ErrNoOperForHost(char *command, char *prefix, char *nick);

/********************************************************************
ERR_YOUREBANNEDCREEP 465

Returned after an attempt to connect and register
yourself with a server which has been setup to
explicitly deny connections to you.
********************************************************************/
long IRC_ErrYoureBannedCreep(char *command, char *prefix, char *nick);

/********************************************************************
ERR_YOUWILLBEBANNED 466

Sent by a server to a user to inform that access to the
server will soon be denied.
********************************************************************/
long IRC_ErrYouWillBeBanned(char *command, char *prefix, char *nick);

/********************************************************************
ERR_BANLISTFULL 478

Returned when a channel access list (i.e. ban list etc) is full and
cannot be added to 
********************************************************************/
long IRC_ErrBanListFull(char *command, char *prefix, char *nick, char *channel, char *character, char *msg);

/********************************************************************
ERR_UNIQOPPRIVSNEEDED 485

Any mode requiring 'channel creator' privileges returns this error
if the client is attempting to use it while not a channel creator
on the given channel 
********************************************************************/
long IRC_ErrUniqOPrivsNeeded(char *command, char *prefix, char *nick, char *msg);













/********************************************************************
ERR_BADMASK 415

412 - 415 are returned by PRIVMSG to indicate that
the message wasn't delivered for some reason.
ERR_NOTOPLEVEL and ERR_WILDTOPLEVEL are errors that
are returned when an invalid use of
PRIVMSG $<server>" or "PRIVMSG #<host>" is attempted.
********************************************************************/
long IRC_ErrBadMask(char *command, char *prefix, char *nick, char *mask);

/********************************************************************
ERR_CANNOTSENDTOCHAN 404

Sent to a user who is either (a) not on a channel
which is mode +n or (b) not a chanop (or mode +v) on
a channel which has mode +m set or where the user is
banned and is trying to send a PRIVMSG message to
that channel.
********************************************************************/
long IRC_ErrCanNotSendToChan(char *command, char *prefix, char *nick, char *channel);

/********************************************************************
ERR_NOTEXTTOSEND 412

412 - 415 are returned by PRIVMSG to indicate that
the message wasn't delivered for some reason.
ERR_NOTOPLEVEL and ERR_WILDTOPLEVEL are errors that
are returned when an invalid use of
PRIVMSG $<server>" or "PRIVMSG #<host>" is attempted.
********************************************************************/
long IRC_ErrNoTextToSend(char *command, char *prefix, char *nick);

/********************************************************************
ERR_NOTOPLEVEL 413

412 - 415 are returned by PRIVMSG to indicate that
the message wasn't delivered for some reason.
ERR_NOTOPLEVEL and ERR_WILDTOPLEVEL are errors that
are returned when an invalid use of
PRIVMSG $<server>" or "PRIVMSG #<host>" is attempted.
********************************************************************/
long IRC_ErrNoTopLevel(char *command, char *prefix, char *nick, char *mask);

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
long IRC_ErrTooManyTargets(char *command, char *prefix, char *nick, char *target, char *errorcode, char *abortmsg);

/********************************************************************
ERR_WILDTOPLEVEL 414

412 - 415 are returned by PRIVMSG to indicate that
the message wasn't delivered for some reason.
ERR_NOTOPLEVEL and ERR_WILDTOPLEVEL are errors that
are returned when an invalid use of
PRIVMSG $<server>" or "PRIVMSG #<host>" is attempted.
********************************************************************/
long IRC_ErrWildTopLevel(char *command, char *prefix, char *nick, char *mask);










/********************************************************************
ERR_CANTKILLSERVER 483

Returned by KILL to anyone who tries to kill a server 
********************************************************************/
long IRC_ErrCantKillServer(char *command, char *prefix, char *nick, char *msg);

/********************************************************************
ERR_NOORIGIN 409

PING or PONG message missing the originator parameter which is
required since these commands must work without valid prefixes 
********************************************************************/
long IRC_ErrNoOrigin(char *command, char *prefix, char *nick, char *msg);







/********************************************************************
RPL_ENDOFUSERS 394

Termination of an RPL_USERS list 
********************************************************************/
long IRC_RplEndOfUsers(char *command, char *prefix, char *nick);

/********************************************************************
ERR_FILEERROR 424

Generic error message used to report a failed file
operation during the processing of a message.
********************************************************************/
long IRC_ErrFileError(char *command, char *prefix, char *nick, char *fileerror, char *file);

/********************************************************************
RPL_ISON 303

Reply format used by ISON to list replies to the
query list
********************************************************************/
long IRC_RplIson(char *command, char *prefix, char *nick, char *nicko1, ...);

/********************************************************************
ERR_NOLOGIN 444

Returned by the summon after a SUMMON command for a
user was unable to be performed since they were not
logged in.
********************************************************************/
long IRC_ErrNoLogin(char *command, char *prefix, char *nick, char *user);


/********************************************************************
RPL_NOUSERS 395

If the USERS message is handled by a server, the
replies RPL_USERSTART, RPL_USERS, RPL_ENDOFUSERS and
RPL_NOUSERS are used.  RPL_USERSSTART MUST be sent
first, following by either a sequence of RPL_USERS
or a single RPL_NOUSER.  Following this is
RPL_ENDOFUSERS.
********************************************************************/
long IRC_RplNoUsers(char *command, char *prefix, char *nick);

/********************************************************************
RPL_NOWAWAY 306

These replies are used with the AWAY command (if
allowed).  RPL_AWAY is sent to any client sending a
PRIVMSG to a client which is away.  RPL_AWAY is only
sent by the server to which the client is connected.
Replies RPL_UNAWAY and RPL_NOWAWAY are sent when the
client removes and sets an AWAY message.
********************************************************************/
long IRC_RplNoAway(char *command, char *prefix, char *nick);

/********************************************************************
RPL_REHASHING 382

If the REHASH option is used and an operator sends
a REHASH message, an RPL_REHASHING is sent back to
the operator.
********************************************************************/
long IRC_RplRehashing(char *command, char *prefix, char *nick, char *configfile);

/********************************************************************
ERR_SUMMONDISABLED 445

Returned as a response to the SUMMON command.  MUST be
returned by any server which doesn't implement it.
********************************************************************/
long IRC_ErrSummonDisabled(char *command, char *prefix, char *nick);

/********************************************************************
long RPL_SUMMONING 342

Returned by a server answering a SUMMON message to
           indicate that it is summoning that user.
********************************************************************/
long IRC_RplSummoning(char *command, char *prefix, char *nick, char *user);

/********************************************************************
RPL_UNAWAY 305

These replies are used with the AWAY command (if
allowed).  RPL_AWAY is sent to any client sending a
PRIVMSG to a client which is away.  RPL_AWAY is only
sent by the server to which the client is connected.
Replies RPL_UNAWAY and RPL_NOWAWAY are sent when the
client removes and sets an AWAY message.
********************************************************************/
long IRC_RplUnaway(char *command, char *prefix, char *nick);

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
long IRC_RplUserHost(char *command, char *prefix, char *nick, char *reply, ...);

/********************************************************************
RPL_USERS 393

If the USERS message is handled by a server, the
replies RPL_USERSTART, RPL_USERS, RPL_ENDOFUSERS and
RPL_NOUSERS are used.  RPL_USERSSTART MUST be sent
first, following by either a sequence of RPL_USERS
or a single RPL_NOUSER.  Following this is
RPL_ENDOFUSERS.
********************************************************************/
long IRC_RplUsers(char *command, char *prefix, char *nick, char *username, char *ttyline, char *hostname);

/********************************************************************
ERR_USERSDISABLED 446

Returned as a response to the USERS command.  MUST be
returned by any server which does not implement it.
********************************************************************/
long IRC_ErrUsersDisabled(char *command, char *prefix, char *nick);

/********************************************************************
RPL_USERSSTART 392

Start of an RPL_USERS list
********************************************************************/
long IRC_RplUsersStart(char *command, char *prefix, char *nick, char *userid, char *terminal, char *host);











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
long IRC_RplAdminMe(char *command, char *prefix, char *nick, char *server, char *admininfo);

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
long IRC_RplAdminLoc1(char *command, char *prefix, char *nick, char *admininfo);

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
long IRC_RplAdminLoc2(char *command, char *prefix, char *nick, char *admininfo);

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
long IRC_RplAdmineMail(char *command, char *prefix, char *nick, char *admininfo);

/********************************************************************
RPL_INFO 371

A server responding to an INFO message is required to
send all its 'info' in a series of RPL_INFO messages
with a RPL_ENDOFINFO reply to indicate the end of the
replies
********************************************************************/
long IRC_RplInfo(char *command, char *prefix, char *nick, char *info);

/********************************************************************
RPL_ENDOFLINKS 365

In replying to the LINKS message, a server MUST send
replies back using the RPL_LINKS numeric and mark the
end of the list using an RPL_ENDOFLINKS reply.
********************************************************************/
long IRC_RplEndOfLinks(char *command, char *prefix, char *nick, char *mask);

/********************************************************************
RPL_ENDOFINFO 374

A server responding to an INFO message is required to
send all its 'info' in a series of RPL_INFO messages
with a RPL_ENDOFINFO reply to indicate the end of the
replies
********************************************************************/
long IRC_RplEndOfInfo(char *command, char *prefix, char *nick);

/********************************************************************
RPL_ENDOFMOTD 376

When responding to the MOTD message and the MOTD file
is found, the file is displayed line by line, with
each line no longer than 80 characters, using
********************************************************************/
long IRC_RplEndOfMotd(char *command, char *prefix, char *nick);

/********************************************************************
RPL_ENDOFSTATS 219

End of RPL_STATS* list. 
********************************************************************/
long IRC_RplEndOfStats(char *command, char *prefix, char *nick, char *query, char *info);

/********************************************************************
RPL_LINKS 364

In replying to the LINKS message, a server MUST send
replies back using the RPL_LINKS numeric and mark the
end of the list using an RPL_ENDOFLINKS reply.
********************************************************************/
long IRC_RplLinks(char *command, char *prefix, char *nick, char *mask, char *server, int hopcount, char *serverinfo);

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
long IRC_RplLuserChannels(char *command, char *prefix, char *nick, int nchannels);

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
long IRC_RplLuserClient(char *command, char *prefix, char *nick, int nusers, int ninvisible, int nservers);

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
long IRC_RplLuserMe(char *command, char *prefix, char *nick, int nclients, int nservers);

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
long IRC_RplLuserOp(char *command, char *prefix, char *nick, int nops);

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
long IRC_RplLuserUnknown(char *command, char *prefix, char *nick, int unknownconn);

/********************************************************************
RPL_MOTD 372

When responding to the MOTD message and the MOTD file
is found, the file is displayed line by line, with
each line no longer than 80 characters, using
RPL_MOTD format replies.  These MUST be surrounded
by a RPL_MOTDSTART (before the RPL_MOTDs) and an
RPL_ENDOFMOTD (after)
********************************************************************/
long IRC_RplMotd(char *command, char *prefix, char *nick, char *msg);

/********************************************************************
RPL_MOTDSTART 375

When responding to the MOTD message and the MOTD file
is found, the file is displayed line by line, with
each line no longer than 80 characters, using
RPL_MOTD format replies.  These MUST be surrounded
by a RPL_MOTDSTART (before the RPL_MOTDs) and an
RPL_ENDOFMOTD (after).
********************************************************************/
long IRC_RplMotdStart(char *command, char *prefix, char *nick, char *server);

/********************************************************************
ERR_NOMOTD 422

Server's MOTD file could not be opened by the server
********************************************************************/
long IRC_ErrNoMotd(char *command, char *prefix, char *nick);

/********************************************************************
RPL_STATSCOMMANDS 212

Reports statistics on commands
********************************************************************/
long IRC_RplStatsCommands(char *command, char *prefix, char *nick, char *commtype, int count, int bytecount, int remotecount);

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
long IRC_RplStatsLinkInfo(char *command, char *prefix, char *nick, char *linkname, int sendq, int sentmessages, int sentKB, int recmessages, int recKB, int timeopen);

/********************************************************************
RPL_STATSOLINE 243

Reports the allowed hosts from where user may become IRC
operators O <hostmask> * <name>
********************************************************************/
long IRC_RplStatsOLine(char *command, char *prefix, char *nick, char *hostmask, char *name);

/********************************************************************
RPL_STATSUPTIME 342

Returned by a server answering a SUMMON message to
indicate that it is summoning that user.
********************************************************************/
long IRC_RplStatsUptime(char *command, char *prefix, char *nick, int days, char *tod);

/********************************************************************
RPL_TIME 391

When replying to the TIME message, a server MUST send
the reply using the RPL_TIME format above.  The string
showing the time need only contain the correct day and
time there.  There is no further requirement for the
time string.
********************************************************************/
long IRC_RplTime(char *command, char *prefix, char *nick, char *server);

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
response to a TRACE command traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRC_RplTraceClass(char *command, char *prefix, char *nick, char *class, int count);

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
response to a TRACE command traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRC_RplTraceConnect(char *command, char *prefix, char *nick);

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
response to a TRACE command traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRC_RplTraceConnecting(char *command, char *prefix, char *nick, char *class, char *server);

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
response to a TRACE command traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRC_RplTraceHandshake(char *command, char *prefix, char *nick, char *class, char *server);

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
response to a TRACE command traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRC_RplTraceLink(char *command, char *prefix, char *nick, int version, int debuglevel, char *dest,
			char *nextserver, int protocolversion, int linkuptime, int backstreamsendq, int upstreamsendq);

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
response to a TRACE command traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRC_RplTraceNewType(char *command, char *prefix, char *nick, char *newtype, char *clientname);

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
response to a TRACE command traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRC_RplTraceOperator(char *command, char *prefix, char *nick, char *class, char *nick2);

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
response to a TRACE command traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRC_RplTraceServer(char *command, char *prefix, char *nick, char *class, int nlinks, int nlinkc,
		   char *server, char *complexuser, int protocolversion);

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
response to a TRACE command traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRC_RplTraceService(char *command, char *prefix, char *nick, char *class, char *name, char *type, char *activetype);

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
response to a TRACE command traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRC_RplTraceUser(char *command, char *prefix, char *nick, char *class, char *nick2);

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
response to a TRACE command traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRC_RplTraceUnknown(char *command, char *prefix, char *nick, char *class, char *ip);

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
response to a TRACE command traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRC_RplTraceLog(char *command, char *prefix, char *nick, char *logfile, int debuglevel);

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
response to a TRACE command traversing the IRC
network should reflect the actual connectivity of
the servers themselves along that path.
RPL_TRACENEWTYPE is to be used for any connection
which does not fit in the other categories but is
being displayed anyway.
RPL_TRACEEND is sent to indicate the end of the list.
********************************************************************/
long IRC_RplTraceEnd(char *command, char *prefix, char *nick, char *servername, int version, int debuglevel);

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
long IRC_RplVersion(char *command, char *prefix, char *nick, int version, int debuglevel, char *server, char *msg);















/********************************************************************
ERR_NOSUCHSERVICE 408

Returned to a client which is attempting to send a SQUERY
to a service which does not exist.
********************************************************************/
long IRC_ErrNoSuchService(char *command, char *prefix, char *nick, char *servicename);

/********************************************************************
RPL_SERVLIST 234

When listing services in reply to a SERVLIST message,
a server is required to send the list back using the
RPL_SERVLIST and RPL_SERVLISTEND messages.  A separate
RPL_SERVLIST is sent for each service.  After the
services have been listed (or if none present) a
RPL_SERVLISTEND MUST be sent.
********************************************************************/
long IRC_RplServList(char *command, char *prefix, char *nick, char *name, char *server, char *mask, char *type, int hopcount, char *info);

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
long IRC_RplServListEnd(char *command, char *prefix, char *nick, char *mask, char *type);












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
long IRC_RplEndOfWho(char *command, char *prefix, char *nick, char *name);

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
long IRC_RplEndOfWhoIs(char *command, char *prefix, char *nick, char *nick2);

/********************************************************************
RPL_ENDOFWHOWAS 369

When replying to a WHOWAS message, a server MUST use
the replies RPL_WHOWASUSER, RPL_WHOISSERVER or
ERR_WASNOSUCHNICK for each nickname in the presented
list.  At the end of all reply batches, there MUST
be RPL_ENDOFWHOWAS (even if there was only one reply
and it was an error)
********************************************************************/
long IRC_RplEndOfWhoWas(char *command, char *prefix, char *nick, char *nick2);

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
long IRC_ErrWasNoSuchNick(char *command, char *prefix, char *nick, char *nickname);

/********************************************************************
RPL_WHOWASUSER 314

When replying to a WHOWAS message, a server MUST use
the replies RPL_WHOWASUSER, RPL_WHOISSERVER or
ERR_WASNOSUCHNICK for each nickname in the presented
list.  At the end of all reply batches, there MUST
be RPL_ENDOFWHOWAS (even if there was only one reply
and it was an error)
********************************************************************/
long IRC_RplWhoWasUser(char *command, char *prefix,char *nick, char *nick2, char *name, char *host, char *realname);

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
long IRC_RplWhoIsUser(char *command, char *prefix,char *nick, char *nick2, char *name, char *host, char *realname);

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
long IRC_RplWhoIsChannels(char *command, char *prefix, char *nick, char *nick2, char *channel, ...);

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
long IRC_RplWhoIsOperator(char *command, char *prefix, char *nick, char *nick2);

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
long IRC_RplWhoIsServer(char *command, char *prefix, char *nick, char *nick2, char *server, char *serverinfo);

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
long IRC_RplWhoIsIdle(char *command, char *prefix, char *nick, char *nick2, int sec_idle, int ref, char *msg);

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
long IRC_WhoReply(char *command, char *prefix, char *nick, char *channel, char *user, char *host, char *server, char *nick2, char *type, int hopcount, char *realname);









/********************************************************************
ERR_ALREADYREGISTRED

Returned by the server to any link which tries to
change part of the registered details (such as
password or user details from second USER message).
********************************************************************/
long IRC_ErrAlredyRegistred(char *command, char *prefix, char *nick);

/********************************************************************
ERR_ERRONEUSNICKNAME

Returned after receiving a NICK message which contains
characters which do not fall in the defined set.
********************************************************************/
long IRC_ErrErroneusNickName(char *command, char *prefix, char *nick, char *erroneusnick);
   
/********************************************************************
RPL_MYINFO

The server sends Replies 001 to 004 to a user upon
successful registration.
********************************************************************/
long IRC_RplMyInfo(char *command, char *prefix, char *nick, char *servername, char *version, char *availableusermodes, char *availablechannelmodes);
  
/********************************************************************
ERR_NICKNAMEINUSE

Returned when a NICK message is processed that results
in an attempt to change to a currently existing
nickname.
********************************************************************/
long IRC_ErrNickNameInUse(char *command, char *prefix, char *nick, char *erroneusnick);
  
/********************************************************************
ERR_NICKCOLLISION

Returned by a server to a client when it detects a
nickname collision (registered of a NICK that
already exists by another server).
********************************************************************/
long IRC_ErrNickCollision(char *command, char *prefix, char *nick, char *nick2, char *user, char *host);

/********************************************************************
ERR_NOOPERHOST

If a client sends an OPER message and the server has
not been configured to allow connections from the
client's host as an operator, this error MUST be
returned.
********************************************************************/
long IRC_ErrNoOperHost(char *command, char *prefix, char *nick);

/********************************************************************
ERR_NOPRIVILEGES

Any command requiring operator privileges to operate
MUST return this error to indicate the attempt was
unsuccessful.
********************************************************************/
long IRC_ErrNoPrivileges(char *command, char *prefix, char *nick);

/********************************************************************
RPL_UMODEIS

To answer a query about a client's own mode,
RPL_UMODEIS is sent back.
********************************************************************/
long IRC_RplUModeIs(char *command, char *prefix, char *nick, char *usermodestring);

/********************************************************************
ERR_UMODEUNKNOWNFLAG

Returned by the server to indicate that a MODE
message was sent with a nickname parameter and that
the a mode flag sent was not recognized.
********************************************************************/
long IRC_ErrUModeUnknownFlag(char *command, char *prefix, char *nick);

/********************************************************************
ERR_USERSDONTMATCH

Error sent to any user trying to view or change the
user mode for a user other than themselves.
********************************************************************/
long IRC_ErrUsersDontMatch(char *command, char *prefix, char *nick);

/********************************************************************
RPL_YOUREOPER

Is sent back to a client which has
just successfully issued an OPER message and gained
operator status.
********************************************************************/
long IRC_RplYoureOper(char *command, char *prefix, char *nick);

/********************************************************************
RPL_YOURHOST

The server sends Replies 001 to 004 to a user upon
successful registration.
********************************************************************/
long IRC_RplYourHost(char *command, char *prefix, char *nick, char *servername, char *versionname);

/********************************************************************
RPL_YOURESERVICE

Sent by the server to a service upon successful
registration.
********************************************************************/
long IRC_RplYoureService(char *command, char *prefix, char *nick, char *servicename);






#endif
