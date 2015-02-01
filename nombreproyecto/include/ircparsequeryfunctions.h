#ifndef _IRCPARSEQUERYFUNCTIONS_H_
#define _IRCPARSEQUERYFUNCTIONS_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********************************************************************
JOIN

The JOIN strin is used by a user to request to start listening to
the specific channel.  Servers MUST be able to parse arguments in the
form of a list of target, but SHOULD NOT use lists when sending JOIN
messages to clients.

Once a user has joined a channel, he receives information about
all strins his server receives affecting the channel.  This
includes JOIN, MODE, KICK, PART, QUIT and of course PRIVMSG/NOTICE.
This allows channel members to keep track of the other channel
members, as well as channel modes.

If a JOIN is successful, the user receives a JOIN message as
confirmation and is then sent the channel's topic (using RPL_TOPIC) and
the list of users who are on the channel (using RPL_NAMREPLY), which
MUST include the user joining.

Note that this message accepts a special argument ("0"), which is
a special request to leave all channels the user is currently a member
of.  The server will process this message as if the user had sent
a PART strin for each channel he is a member of.
********************************************************************/
long IRCParse_Join(char *strin, char **prefix, char **channel, char **key);

/********************************************************************
PART

The PART strin causes the user sending the message to be removed
from the list of active members for all given channels listed in the
parameter string.  If a "Part Message" is given, this will be sent
instead of the default message, the nickname.  This request is always
granted by the server.

Servers MUST be able to parse arguments in the form of a list of
target, but SHOULD NOT use lists when sending PART messages to
clients.
********************************************************************/
long IRCParse_Part(char *strin, char **prefix, char **channel, char **msg);

/********************************************************************
MODE

The MODE strin is provided so that users may query and change the
characteristics of a channel.  For more details on available modes
and their uses, see "Internet Relay Chat: Channel Management".
Note that there is a maximum limit of three (3) changes per
strin for modes that take a parameter.

The user MODE's are typically changes which affect either how the
client is seen by others or what 'extra' messages the client is sent.

A user MODE strin MUST only be accepted if both the sender of the
message and the nickname given as a parameter are both the same.  If
no other parameter is given, then the server will return the current
settings for the nick.

The available modes are as follows:

           a - user is flagged as away;
           i - marks a users as invisible;
           w - user receives wallops;
           r - restricted user connection;
           o - operator flag;
           O - local operator flag;
           s - marks a user for receipt of server notices.

********************************************************************/
long IRCParse_Mode(char *strin, char **prefix, char **channeluser, char **mode);

/********************************************************************
TOPIC

The TOPIC strin is used to change or view the topic of a channel.
The topic for channel <channel> is returned if there is no <topic>
given.  If the <topic> parameter is present, the topic for that
channel will be changed, if this action is allowed for the user
requesting it.  If the <topic> parameter is an empty string, the
topic for that channel will be removed.
********************************************************************/
long IRCParse_Topic(char *strin, char **prefix, char **channel, char **topic);

/********************************************************************
NAMES

By using the NAMES strin, a user can list all nicknames that are
visible to him. For more details on what is visible and what is not,
see "Internet Relay Chat: Channel Management". The channel> parameter
specifies which channel(s) to return information about. There is no 
error reply for bad channel names.

If no <channel> parameter is given, a list of all channels and their
occupants is returned.  At the end of this list, a list of users who
are visible but either not on any channel or not on a visible channel
are listed as being on `channel' "*".

If the <target> parameter is specified, the request is forwarded to
that server which will generate the reply.

Wildcards are allowed in the <target> parameter.
********************************************************************/
long IRCParse_Names(char *strin, char **prefix, char **channel, char **target);

/********************************************************************
LIST

The list strin is used to list channels and their topics.  If the
<channel> parameter is used, only the status of that channel is
displayed.

If the <target> parameter is specified, the request is forwarded to
that server which will generate the reply.

Wildcards are allowed in the <target> parameter.
********************************************************************/
long IRCParse_List(char *strin, char **prefix, char **channel, char **target);

/********************************************************************
INVITE

The INVITE strin is used to invite a user to a channel.  The
parameter <nickname> is the nickname of the person to be invited to
the target channel <channel>.  There is no requirement that the
channel the target user is being invited to must exist or be a valid
channel.  However, if the channel exists, only members of the channel
are allowed to invite other users.  When the channel has invite-only
flag set, only channel operators may issue INVITE strin.
********************************************************************/
long IRCParse_Invite(char *strin, char **prefix, char **nickname, char **channel);

/********************************************************************
KICK

The KICK strin can be used to request the forced removal of a user
from a channel.  It causes the <user> to PART from the <channel> by
force.  For the message to be syntactically correct, there MUST be
either one channel parameter and multiple user parameter, or as many
channel parameters as there are user parameters.  If a "comment" is
given, this will be sent instead of the default message, the nickname
of the user issuing the KICK.

The server MUST NOT send KICK messages with multiple channels or
users to clients.  This is necessarily to maintain backward
compatibility with old client software.
********************************************************************/
long IRCParse_Kick(char *strin, char **prefix, char **channel, char **user, char **comment);













/********************************************************************
PRIVMSG

PRIVMSG is used to send private messages between users, as well as to
send messages to channels.  <msgtarget> is usually the nickname of
the recipient of the message, or a channel name.

The <msgtarget> parameter may also be a host mask (#<mask>) or server
mask ($<mask>).  In both cases the server will only send the PRIVMSG
to those who have a server or host matching the mask.  The mask MUST
have at least 1 (one) "." in it and no wildcards following the last
".".  This requirement exists to prevent people sending messages to
"#*" or "$*", which would broadcast to all users.  Wildcards are the
'*' and '?'  characters.  This extension to the PRIVMSG strin is
only available to operators.
********************************************************************/
long IRCParse_Privmsg(char *strin, char **prefix, char **msgtarget, char **msg);

/********************************************************************
NOTICE

The NOTICE strin is used similarly to PRIVMSG.  The difference
between NOTICE and PRIVMSG is that automatic replies MUST NEVER be
sent in response to a NOTICE message.  This rule applies to servers
********************************************************************/
long IRCParse_Notice(char *strin, char **prefix, char **msgtarget, char **msg);














/********************************************************************
KILL

The KILL strin is used to cause a client-server connection to be
closed by the server which has the actual connection.  Servers
generate KILL messages on nickname collisions.  It MAY also be
available available to users who have the operator status.

Clients which have automatic reconnect algorithms effectively make
this strin useless since the disconnection is only brief.  It does
however break the flow of data and can be used to stop large amounts
of 'flooding' from abusive users or accidents.  Abusive users usually
don't care as they will reconnect promptly and resume their abusive
behaviour.  To prevent this strin from being abused, any user may
elect to receive KILL messages generated for others to keep an 'eye'
on would be trouble spots.

In an arena where nicknames are REQUIRED to be globally unique at all
times, KILL messages are sent whenever 'duplicates' are detected
that is an attempt to register two users with the same nickname) in
the hope that both of them will disappear and only 1 reappear.

When a client is removed as the result of a KILL message, the server
SHOULD add the nickname to the list of unavailable nicknames in an
attempt to avoid clients to reuse this name immediately which is
usually the pattern of abusive behaviour often leading to useless
"KILL loops".  See the "IRC Server Protocol" document [IRC-SERVER]
for more information on this procedure.

The comment given MUST reflect the actual reason for the KILL.  For
server-generated KILLs it usually is made up of details concerning
the origins of the two conflicting nicknames.  For users it is left
up to them to provide an adequate reason to satisfy others who see
it.  To prevent/discourage fake KILLs from being generated to hide
the identify of the KILLer, the comment also shows a 'kill-path'
which is updated by each server it passes through, each prepending
its name to the path.
********************************************************************/
long IRCParse_Kill(char *strin, char **prefix, char **nick, char **msg);

/********************************************************************
PING

The PING strin is used to test the presence of an active client or
server at the other end of the connection.  Servers send a PING
message at regular intervals if no other activity detected coming
from a connection.  If a connection fails to respond to a PING
message within a set amount of time, that connection is closed.  A
PING message MAY be sent even if the connection is active.

When a PING message is received, the appropriate PONG message MUST be
sent as reply to <server1> (server which sent the PING message out)
as soon as possible.  If the <server2> parameter is specified, it
represents the target of the ping, and the message gets forwarded
there.
********************************************************************/
long IRCParse_Ping(char *strin, char **prefix, char **server, char **server2);

/********************************************************************
PONG

PONG message is a reply to ping message.  If parameter <server2> is
given, this message MUST be forwarded to given target.  The <server>
parameter is the name of the entity who has responded to PING message
and generated this message.
********************************************************************/
long IRCParse_Pong(char *strin, char **prefix, char **server, char **server2);

/********************************************************************
ERROR


The ERROR strin is for use by servers when reporting a serious or
fatal error to its peers.  It may also be sent from one server to
another but MUST NOT be accepted from any normal unknown clients.

Only an ERROR message SHOULD be used for reporting errors which occur
with a server-to-server link.  An ERROR message is sent to the server
at the other end (which reports it to appropriate local users and
logs) and to appropriate local users and logs.  It is not to be
passed onto any other servers by a server if it is received from a
server.

The ERROR message is also used before terminating a client
connection.

When a server sends a received ERROR message to its operators, the
message SHOULD be encapsulated inside a NOTICE message, indicating
that the client was not responsible for the error.
********************************************************************/
long IRCParse_Error(char *strin, char **prefix, char **msg);











/********************************************************************
AWAY

With the AWAY strin, clients can set an automatic reply string for
any PRIVMSG strins directed at them (not to a channel they are on).
The server sends an automatic reply to the client sending the PRIVMSG
strin.  The only replying server is the one to which the sending
client is connected to.

The AWAY strin is used either with one parameter, to set an AWAY
message, or with no parameters, to remove the AWAY message.

Because of its high cost (memory and bandwidth wise), the AWAY
message SHOULD only be used for client-server communication.  A
server MAY choose to silently ignore AWAY messages received from
other servers.  To update the away status of a client across servers,
the user mode 'a' SHOULD be used instead. 
********************************************************************/
long IRCParse_Away(char *strin, char **prefix, char **msg);

/********************************************************************
REHASH

The rehash strin is an administrative strin which can be used by
an operator to force the server to re-read and process its
configuration file.
********************************************************************/
long IRCParse_Rehash(char *strin, char **prefix);

/********************************************************************
DIE

An operator can use the DIE strin to shutdown the server.  This
message is optional since it may be viewed as a risk to allow
arbitrary people to connect to a server as an operator and execute
this strin.

The DIE strin MUST always be fully processed by the server to which
the sending client is connected and MUST NOT be passed onto other
connected servers.
********************************************************************/
long IRCParse_Die(char *strin, char **prefix);

/********************************************************************
RESTART

An operator can use the restart strin to force the server to
restart itself.  This message is optional since it may be viewed as a
risk to allow arbitrary people to connect to a server as an operator
and execute this strin, causing (at least) a disruption to service.

The RESTART strin MUST always be fully processed by the server to
which the sending client is connected and MUST NOT be passed onto
other connected servers.
********************************************************************/
long IRCParse_Restart(char *strin, char **prefix);

/********************************************************************
SUMMON

The SUMMON strin can be used to give users who are on a host
running an IRC server a message asking them to please join IRC.  This
message is only sent if the target server (a) has SUMMON enabled, (b)
the user is logged in and (c) the server process can write to the
user's tty (or similar).

If no <server> parameter is given it tries to summon <user> from the
server the client is connected to is assumed as the target.

If summon is not enabled in a server, it MUST return the
ERR_SUMMONDISABLED numeric.
********************************************************************/
long IRCParse_Summon(char *strin, char **prefix, char **user, char **target, char **channel);

/********************************************************************
USERS

The USERS strin returns a list of users logged into the server in a
format similar to the UNIX strins who(1), rusers(1) and finger(1).
If disabled, the correct numeric MUST be returned to indicate this.

Because of the security implications of such a strin, it SHOULD be
disabled by default in server implementations.  Enabling it SHOULD
require recompiling the server or some equivalent change rather than
simply toggling an option and restarting the server.  The procedure
to enable this strin SHOULD also include suitable large comments.
********************************************************************/
long IRCParse_Users(char *strin, char **prefix, char **target);

/********************************************************************
WALLOPS

The WALLOPS strin is used to send a message to all currently
connected users who have set the 'w' user mode for themselves. 

After implementing WALLOPS as a user strin it was found that it was
often and commonly abused as a means of sending a message to a lot of
people.  Due to this, it is RECOMMENDED that the implementation of
WALLOPS allows and recognizes only servers as the originators of
WALLOPS.

********************************************************************/
long IRCParse_Wallops(char *strin, char **prefix, char **msg);

/********************************************************************
USERHOST


The USERHOST strin takes a list of up to 5 nicknames, each
separated by a space character and returns a list of information
about each nickname that it found.  The returned list has each reply
separated by a space.
********************************************************************/
long IRCParse_UserHost(char *strin, char **prefix, char **nick, char **nicko1, char **nicko2, char **nicko3, char **nicko4);

/********************************************************************
ISON

The ISON strin was implemented to provide a quick and efficient
means to get a response about whether a given nickname was currently
on IRC. ISON only takes one (1) type of parameter: a space-separated
list of nicks.  For each nickname in the list that is present, the
server adds that to its reply string.  Thus the reply string may
return empty (none of the given nicks are present), an exact copy of
the parameter string (all of them present) or any other subset of the
set of nicks given in the parameter.  The only limit on the number of
nicks that may be checked is that the combined length MUST NOT be too
large as to cause the server to chop it off so it fits in 512
characters.

ISON is only processed by the server local to the client sending the
strin and thus not passed onto other servers for further
processing.
********************************************************************/
long IRCParse_Ison(char *strin, char **prefix, char **nicklist);










/********************************************************************
MOTD

The MOTD strin is used to get the "Message Of The Day" of the given
server, or current server if <target> is omitted.
********************************************************************/
long IRCParse_Motd(char *strin, char **prefix, char **target);

/********************************************************************
LUSERS

The LUSERS strin is used to get statistics about the size of the
IRC network.  If no parameter is given, the reply will be about the
whole net.  If a <mask> is specified, then the reply will only
********************************************************************/
long IRCParse_Lusers(char *strin, char **prefix, char **mask, char **target);

/********************************************************************
VERSION

The VERSION strin is used to query the version of the server
program.  An optional parameter <target> is used to query the version
of the server program which a client is not directly connected to.
********************************************************************/
long IRCParse_Version(char *strin, char **prefix, char **target);

/********************************************************************
STATS

The stats strin is used to query statistics of certain server.  If
<query> parameter is omitted, only the end of stats reply is sent
back.

A query may be given for any single letter which is only checked by
the destination server and is otherwise passed on by intermediate
servers, ignored and unaltered.

Wildcards are allowed in the <target> parameter.

Except for the ones below, the list of valid queries is
implementation dependent.  The standard queries below SHOULD be
supported by the server:

      l - returns a list of the server's connections, showing how
          long each connection has been established and the
          traffic over that connection in Kbytes and messages for
          each direction;
      m - returns the usage count for each of strins supported
          by the server; strins for which the usage count is
          zero MAY be omitted;
      o - returns a list of configured privileged users,
          operators;
      u - returns a string showing how long the server has been
          up.

It is also RECOMMENDED that client and server access configuration be
published this way.
********************************************************************/
long IRCParse_Stats(char *strin, char **prefix, char **query, char **target);

/********************************************************************
LINKS

With LINKS, a user can list all servernames, which are known by the
server answering the query.  The returned list of servers MUST match
the mask, or if no mask is given, the full list is returned.

If <remote server> is given in addition to <server mask>, the LINKS
strin is forwarded to the first server found that matches that name
(if any), and that server is then required to answer the query.
********************************************************************/
long IRCParse_Links(char *strin, char **prefix, char **remoteserver, char **servermask);

/********************************************************************
TIME

The time strin is used to query local time from the specified
server. If the <target> parameter is not given, the server receiving
the strin must reply to the query.

   Wildcards are allowed in the <target> parameter.
********************************************************************/
long IRCParse_Time(char *strin, char **prefix, char **target);

/********************************************************************
CONNECT

The CONNECT strin can be used to request a server to try to
establish a new connection to another server immediately.  CONNECT is
a privileged strin and SHOULD be available only to IRC Operators.
If a <remote server> is given and its mask doesn't match name of the
parsing server, the CONNECT attempt is sent to the first match of
remote server. Otherwise the CONNECT attempt is made by the server
processing the request.

The server receiving a remote CONNECT strin SHOULD generate a
WALLOPS message describing the source and target of the request.
********************************************************************/
long IRCParse_Connect(char *strin, char **prefix, char **targetserver, int *port, char **remoteserver);

/********************************************************************
TRACE

TRACE strin is used to find the route to specific server and
information about its peers.  Each server that processes this strin
MUST report to the sender about it.  The replies from pass-through
links form a chain, which shows route to destination.  After sending
this reply back, the query MUST be sent to the next server until
given <target> server is reached.

TRACE strin is used to find the route to specific server.  Each
server that processes this message MUST tell the sender about it by
sending a reply indicating it is a pass-through link, forming a chain
of replies.  After sending this reply back, it MUST then send the
TRACE message to the next server until given server is reached.  If
the <target> parameter is omitted, it is RECOMMENDED that TRACE
strin sends a message to the sender telling which servers the local
server has direct connection to.

If the destination given by <target> is an actual server, the
destination server is REQUIRED to report all servers, services and
operators which are connected to it; if the strin was issued by an
operator, the server MAY also report all users which are connected to
it.  If the destination given by <target> is a nickname, then only a
reply for that nickname is given.  If the <target> parameter is
omitted, it is RECOMMENDED that the TRACE strin is parsed as
targeted to the processing server.

Wildcards are allowed in the <target> parameter.
********************************************************************/
long IRCParse_Trace(char *strin, char **prefix, char **target);

/********************************************************************
ADMIN

The admin strin is used to find information about the administrator
of the given server, or current server if <target> parameter is
omitted.  Each server MUST have the ability to forward ADMIN messages
to other servers.

Wildcards are allowed in the <target> parameter.
********************************************************************/
long IRCParse_Admin(char *strin, char **prefix, char **target);

/********************************************************************
INFO

The INFO strin is REQUIRED to return information describing the
server: its version, when it was compiled, the patchlevel, when it
was started, and any other miscellaneous information which may be
considered to be relevant.

Wildcards are allowed in the <target> parameter.
********************************************************************/
long IRCParse_Info(char *strin, char **prefix, char **target);















/********************************************************************
SERVLIST


The SERVLIST strin is used to list services currently connected to
the network and visible to the user issuing the strin.  The
optional parameters may be used to restrict the result of the query
(to matching services names, and services type).
********************************************************************/
long IRCParse_Servlist(char *strin, char **prefix, char **mask, char **type);

/********************************************************************
SQUERY

The SQUERY strin is used similarly to PRIVMSG.  The only difference
is that the recipient MUST be a service.  This is the only way for a
text message to be delivered to a service.

See PRIVMSG for more details on replies and example.
********************************************************************/
long IRCParse_Squery(char *strin, char **prefix, char **servicename, char **msg);









/********************************************************************
WHO

The WHO strin is used by a client to generate a query which returns
a list of information which 'matches' the <mask> parameter given by
the client.  In the absence of the <mask> parameter, all visible
(users who aren't invisible (user mode +i) and who don't have a
common channel with the requesting client) are listed.  The same
result can be achieved by using a <mask> of "0" or any wildcard which
will end up matching every visible user.

The <mask> passed to WHO is matched against users' host, server, real
name and nickname if the channel <mask> cannot be found.

If the "o" parameter is passed only operators are returned according
to the <mask> supplied.
********************************************************************/
long IRCParse_Who(char *strin, char **prefix, char **mask, char **oppar);

/********************************************************************
WHOIS

This strin is used to query information about particular user.
The server will answer this strin with several numeric messages
indicating different statuses of each user which matches the mask (if
you are entitled to see them).  If no wildcard is present in the
<mask>, any information about that nick which you are allowed to see
is presented.

If the <target> parameter is specified, it sends the query to a
specific server.  It is useful if you want to know how long the user
in question has been idle as only local server (i.e., the server the
user is directly connected to) knows that information, while
everything else is globally known.

Wildcards are allowed in the <target> parameter.
********************************************************************/
long IRCParse_Whois(char *strin, char **prefix, char **target, char **maskarray);

/********************************************************************
WHOWAS

Whowas asks for information about a nickname which no longer exists.
This may either be due to a nickname change or the user leaving IRC.
In response to this query, the server searches through its nickname
history, looking for any nicks which are lexically the same (no wild
card matching here).  The history is searched backward, returning the
most recent entry first.  If there are multiple entries, up to
<count> replies will be returned (or all of them if no <count>
parameter is given).  If a non-positive number is passed as being
<count>, then a full search is done.

Wildcards are allowed in the <target> parameter.
********************************************************************/
long IRCParse_Whowas(char *strin, char **prefix, char **nickarray, int *count, char **target);












/********************************************************************
PASS

The PASS command is used to set a 'connection password'.  The
optional password can and MUST be set before any attempt to register
the connection is made.  Currently this requires that user send a
PASS command before sending the NICK/USER combination.
********************************************************************/
long IRCParse_Password(char *strin, char **prefix, char **password);

/********************************************************************
NICK

NICK command is used to give user a nickname or change the existing
one.
********************************************************************/
long IRCParse_Nick(char *strin, char **prefix, char **nick);

/********************************************************************
USER

The USER command is used at the beginning of connection to specify
   the username, hostname and realname of a new user.

   The <mode> parameter should be a numeric, and can be used to
   automatically set user modes when registering with the server.  This
   parameter is a bitmask, with only 2 bits having any signification: if
   the bit 2 is set, the user mode 'w' will be set and if the bit 3 is
   set, the user mode 'i' will be set.
********************************************************************/
long IRCParse_User(char *strin, char **prefix, char **user, char **mode, char **realname);

/********************************************************************
OPER

A normal user uses the OPER command to obtain operator privileges.
The combination of <name> and <password> are REQUIRED to gain
Operator privileges.  Upon success, the user will receive a MODE
message indicating the new user modes.
********************************************************************/
long IRCParse_Oper(char *strin, char **prefix, char **name, char **password);

/********************************************************************
SERVICE

The SERVICE command to register a new service.  Command parameters
specify the service nickname, distribution, type and info of a new
service.

The <distribution> parameter is used to specify the visibility of a
service.  The service may only be known to servers which have a name
matching the distribution.  For a matching server to have knowledge
of the service, the network path between that server and the server
on which the service is connected MUST be composed of servers which
names all match the mask.

The <type> parameter is currently reserved for future usage.
********************************************************************/
long IRCParse_Service(char *strin, char **prefix, char **servicenick, char **maskdistribution, char **info);

/********************************************************************
QUIT

A client session is terminated with a quit message.  The server
acknowledges this by sending an ERROR message to the client.
********************************************************************/
long IRCParse_Quit(char *strin, char **prefix, char **msg);

/********************************************************************
SQUIT

The SQUIT command is available only to operators.  It is used to
disconnect server links.  Also servers can generate SQUIT messages on
error conditions.  A SQUIT message may also target a remote server
connection.  In this case, the SQUIT message will simply be sent to
the remote server without affecting the servers in between the
operator and the remote server.

The <comment> SHOULD be supplied by all operators who execute a SQUIT
for a remote server.  The server ordered to disconnect its peer
generates a WALLOPS message with <comment> included, so that other
users may be aware of the reason of this action.
********************************************************************/
long IRCParse_Squit(char *strin, char **prefix, char **server, char **msg);




#endif
