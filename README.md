[![License][license-logo]][license-url]

<br />
<p align="center">
  <h2 align="center">ft_containers</h2>

  <p align="center">
    C++ containers, easy mode
  </p>
</p>


<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
  </ol>
</details>

---

## About The Project

The multiple available containers in C++ all have a very different usage. To make sure you understand them all, let’s re-implement them!

In this project you will implement the various container types of the C++ standard template library. For each container, turn in the appropriately named class files. The namespace will always be ft and your containers will be tested using `ft::<container>`.
Each class must be in Coplien form. As a reminder, we are coding in C++98, so any new feature of the containers MUST NOT be implemented, but every old feature (even deprecated) is expected.

---

### Madatory Part

You cannot implement more public functions than the ones offered in the standard containers. Everything else must be private or protected. Each public function/variable must be justified.

You are only allowed to use the STD library.

You must turn in the following containers and their associated functions:
- **List**
- **Vector**
- **Map**
- **Stack**
- **Queue**

### Bonus Part

As a bonus, you can turn in the following containers and their associated functions:
- **Deque** `(not implemented)`
- **Set**
- **Multiset**
- **Multimap**

## Getting Started

### Installation

1. Clone the repository
    ```sh
    $ git clone https://github.com/pabloocg/ft_containers.git
    ```
2. Enter the repository and run make
    ```sh
    $ cd ft_containers && make
    ```

## Usage

To test the containers you can do:
```sh
$ make {container_name}

> make list
./ft_containers list_test > FT_LIST.TXT
./ft_containers list_sys > STD_LIST.TXT
diff FT_LIST.TXT STD_LIST.TXT
```

A series of tests are run on the created container and compared with those of the original system container.

## License

Distributed under the GNU GPLv3. See `LICENSE` for more information.

## Contact

Pablo Cuadrado García </br>
[Linkedin][linkedin-url] - pablocuadrado97@gmail.com

[license-logo]: https://img.shields.io/cran/l/devtools?style=for-the-badge
[license-url]: https://github.com/pabloocg/ft_containers/LICENSE
[linkedin-url]: https://linkedin.com/in/pablo-cuadrado97
