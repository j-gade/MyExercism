namespace hellmath {

// Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.
enum class AccountStatus {
     troll
    ,guest
    ,user
    ,mod
};

// Task 1 - Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.
enum class Action {
     read
    ,write
    ,remove
};

// Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.
bool display_post(AccountStatus poster, AccountStatus viewer) {
    // This relies on short-circuit behavior to shorten the logic
    return poster != AccountStatus::troll || viewer == AccountStatus::troll;
}
    
// Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.
bool permission_check(Action action, AccountStatus account) {
    bool has_permission{false};
    switch (account) {
        case AccountStatus::mod:
            has_permission = true;
            break;
        case AccountStatus::user:
        case AccountStatus::troll:
            has_permission = (action == Action::read || action == Action::write);
            break;
        case AccountStatus::guest:
            has_permission = action == Action::read;
            break;
        // Should not get here.
        default:
            has_permission = false;    
    }
    return has_permission;
}
// Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.
bool valid_player_combination(AccountStatus player_one, AccountStatus player_two) {
    bool has_guest = player_one == AccountStatus::guest || player_two == AccountStatus::guest;
    bool one_troll = player_one == AccountStatus::troll || player_two == AccountStatus::troll;
    bool only_trolls = player_one == AccountStatus::troll && player_two == AccountStatus::troll;
    return (!has_guest && !one_troll) || only_trolls;
}
    
// Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.
bool has_priority(AccountStatus player_one, AccountStatus player_two) {
    return player_one > player_two;
}

}  // namespace hellmath