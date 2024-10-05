PGDMP       !                 |            inepo    16.1    16.1 )    '           0    0    ENCODING    ENCODING        SET client_encoding = 'UTF8';
                      false            (           0    0 
   STDSTRINGS 
   STDSTRINGS     (   SET standard_conforming_strings = 'on';
                      false            )           0    0 
   SEARCHPATH 
   SEARCHPATH     8   SELECT pg_catalog.set_config('search_path', '', false);
                      false            *           1262    16404    inepo    DATABASE     x   CREATE DATABASE inepo WITH TEMPLATE = template0 ENCODING = 'UTF8' LOCALE_PROVIDER = libc LOCALE = 'Spanish_Spain.1252';
    DROP DATABASE inepo;
                postgres    false            �            1259    16417    compra    TABLE     �   CREATE TABLE public.compra (
    usuari text NOT NULL,
    element text NOT NULL,
    data date NOT NULL,
    preu_pagat integer NOT NULL,
    CONSTRAINT preu_pagat CHECK ((preu_pagat > 0))
);
    DROP TABLE public.compra;
       public         heap    postgres    false            �            1259    16447    conte    TABLE     T   CREATE TABLE public.conte (
    paquet text NOT NULL,
    videojoc text NOT NULL
);
    DROP TABLE public.conte;
       public         heap    postgres    false            �            1259    16426    element_compra    TABLE     -  CREATE TABLE public.element_compra (
    nom text NOT NULL,
    descripcio text NOT NULL,
    preu double precision NOT NULL,
    tipus text NOT NULL,
    CONSTRAINT preu CHECK ((preu >= (0)::double precision)),
    CONSTRAINT tipus CHECK (((tipus = 'paquet'::text) OR (tipus = 'videojoc'::text)))
);
 "   DROP TABLE public.element_compra;
       public         heap    postgres    false            �            1259    16454    genere    TABLE     6   CREATE TABLE public.genere (
    nom text NOT NULL
);
    DROP TABLE public.genere;
       public         heap    postgres    false            �            1259    16433    paquet_videojocs    TABLE     @   CREATE TABLE public.paquet_videojocs (
    nom text NOT NULL
);
 $   DROP TABLE public.paquet_videojocs;
       public         heap    postgres    false            �            1259    16512 	   preu_jocs    VIEW     >  CREATE VIEW public.preu_jocs AS
 SELECT paquet_videojocs.nom AS nom_paquet,
    sum(element_compra.preu) AS preu_jocs
   FROM public.conte,
    public.paquet_videojocs,
    public.element_compra
  WHERE ((conte.paquet = paquet_videojocs.nom) AND (conte.videojoc = element_compra.nom))
  GROUP BY paquet_videojocs.nom;
    DROP VIEW public.preu_jocs;
       public          postgres    false    220    217    217    218    220            �            1259    16410    usuari    TABLE     �   CREATE TABLE public.usuari (
    nom text NOT NULL,
    sobrenom text NOT NULL,
    contrasenya text NOT NULL,
    correu_electronic text NOT NULL,
    data_naixament date NOT NULL
);
    DROP TABLE public.usuari;
       public         heap    postgres    false            �            1259    16440    videojoc    TABLE     z  CREATE TABLE public.videojoc (
    nom text NOT NULL,
    qualificacio_edat integer NOT NULL,
    data_llansament date NOT NULL,
    mins_estimat integer NOT NULL,
    genere text NOT NULL,
    CONSTRAINT mins_estimat CHECK (((mins_estimat = NULL::integer) OR (mins_estimat > 0))),
    CONSTRAINT qualificacio_edat CHECK ((qualificacio_edat = ANY (ARRAY[3, 7, 12, 16, 18])))
);
    DROP TABLE public.videojoc;
       public         heap    postgres    false                      0    16417    compra 
   TABLE DATA           C   COPY public.compra (usuari, element, data, preu_pagat) FROM stdin;
    public          postgres    false    216   
.       #          0    16447    conte 
   TABLE DATA           1   COPY public.conte (paquet, videojoc) FROM stdin;
    public          postgres    false    220   '.                  0    16426    element_compra 
   TABLE DATA           F   COPY public.element_compra (nom, descripcio, preu, tipus) FROM stdin;
    public          postgres    false    217   D.       $          0    16454    genere 
   TABLE DATA           %   COPY public.genere (nom) FROM stdin;
    public          postgres    false    221   a.       !          0    16433    paquet_videojocs 
   TABLE DATA           /   COPY public.paquet_videojocs (nom) FROM stdin;
    public          postgres    false    218   ~.                 0    16410    usuari 
   TABLE DATA           _   COPY public.usuari (nom, sobrenom, contrasenya, correu_electronic, data_naixament) FROM stdin;
    public          postgres    false    215   �.       "          0    16440    videojoc 
   TABLE DATA           a   COPY public.videojoc (nom, qualificacio_edat, data_llansament, mins_estimat, genere) FROM stdin;
    public          postgres    false    219   �.       u           2606    16423    compra Compra_pkey 
   CONSTRAINT     _   ALTER TABLE ONLY public.compra
    ADD CONSTRAINT "Compra_pkey" PRIMARY KEY (usuari, element);
 >   ALTER TABLE ONLY public.compra DROP CONSTRAINT "Compra_pkey";
       public            postgres    false    216    216            �           2606    16460    genere Genere_pkey 
   CONSTRAINT     S   ALTER TABLE ONLY public.genere
    ADD CONSTRAINT "Genere_pkey" PRIMARY KEY (nom);
 >   ALTER TABLE ONLY public.genere DROP CONSTRAINT "Genere_pkey";
       public            postgres    false    221            q           2606    16416    usuari Usuari_pkey 
   CONSTRAINT     X   ALTER TABLE ONLY public.usuari
    ADD CONSTRAINT "Usuari_pkey" PRIMARY KEY (sobrenom);
 >   ALTER TABLE ONLY public.usuari DROP CONSTRAINT "Usuari_pkey";
       public            postgres    false    215            ~           2606    16446    videojoc Videojoc_pkey 
   CONSTRAINT     W   ALTER TABLE ONLY public.videojoc
    ADD CONSTRAINT "Videojoc_pkey" PRIMARY KEY (nom);
 B   ALTER TABLE ONLY public.videojoc DROP CONSTRAINT "Videojoc_pkey";
       public            postgres    false    219            �           2606    16453    conte conte_pkey 
   CONSTRAINT     \   ALTER TABLE ONLY public.conte
    ADD CONSTRAINT conte_pkey PRIMARY KEY (paquet, videojoc);
 :   ALTER TABLE ONLY public.conte DROP CONSTRAINT conte_pkey;
       public            postgres    false    220    220            s           2606    16425    usuari correuElectronic 
   CONSTRAINT     a   ALTER TABLE ONLY public.usuari
    ADD CONSTRAINT "correuElectronic" UNIQUE (correu_electronic);
 C   ALTER TABLE ONLY public.usuari DROP CONSTRAINT "correuElectronic";
       public            postgres    false    215            y           2606    16432 "   element_compra element_compra_pkey 
   CONSTRAINT     a   ALTER TABLE ONLY public.element_compra
    ADD CONSTRAINT element_compra_pkey PRIMARY KEY (nom);
 L   ALTER TABLE ONLY public.element_compra DROP CONSTRAINT element_compra_pkey;
       public            postgres    false    217            |           2606    16439 &   paquet_videojocs paquet_videojocs_pkey 
   CONSTRAINT     e   ALTER TABLE ONLY public.paquet_videojocs
    ADD CONSTRAINT paquet_videojocs_pkey PRIMARY KEY (nom);
 P   ALTER TABLE ONLY public.paquet_videojocs DROP CONSTRAINT paquet_videojocs_pkey;
       public            postgres    false    218                       1259    16474    fki_e    INDEX     9   CREATE INDEX fki_e ON public.videojoc USING btree (nom);
    DROP INDEX public.fki_e;
       public            postgres    false    219            v           1259    16494    fki_element    INDEX     A   CREATE INDEX fki_element ON public.compra USING btree (element);
    DROP INDEX public.fki_element;
       public            postgres    false    216            �           1259    16466 
   fki_genere    INDEX     A   CREATE INDEX fki_genere ON public.videojoc USING btree (genere);
    DROP INDEX public.fki_genere;
       public            postgres    false    219            z           1259    16482    fki_nom    INDEX     C   CREATE INDEX fki_nom ON public.paquet_videojocs USING btree (nom);
    DROP INDEX public.fki_nom;
       public            postgres    false    218            �           1259    16501 
   fki_paquet    INDEX     >   CREATE INDEX fki_paquet ON public.conte USING btree (paquet);
    DROP INDEX public.fki_paquet;
       public            postgres    false    220            w           1259    16488 
   fki_usuari    INDEX     ?   CREATE INDEX fki_usuari ON public.compra USING btree (usuari);
    DROP INDEX public.fki_usuari;
       public            postgres    false    216            �           1259    16507    fki_videojoc    INDEX     B   CREATE INDEX fki_videojoc ON public.conte USING btree (videojoc);
     DROP INDEX public.fki_videojoc;
       public            postgres    false    220            �           2606    16489    compra element    FK CONSTRAINT     �   ALTER TABLE ONLY public.compra
    ADD CONSTRAINT element FOREIGN KEY (element) REFERENCES public.element_compra(nom) ON DELETE CASCADE;
 8   ALTER TABLE ONLY public.compra DROP CONSTRAINT element;
       public          postgres    false    217    4729    216            �           2606    16461    videojoc genere    FK CONSTRAINT     o   ALTER TABLE ONLY public.videojoc
    ADD CONSTRAINT genere FOREIGN KEY (genere) REFERENCES public.genere(nom);
 9   ALTER TABLE ONLY public.videojoc DROP CONSTRAINT genere;
       public          postgres    false    221    4742    219            �           2606    16469    videojoc nom    FK CONSTRAINT     q   ALTER TABLE ONLY public.videojoc
    ADD CONSTRAINT nom FOREIGN KEY (nom) REFERENCES public.element_compra(nom);
 6   ALTER TABLE ONLY public.videojoc DROP CONSTRAINT nom;
       public          postgres    false    4729    219    217            �           2606    16477    paquet_videojocs nom    FK CONSTRAINT     y   ALTER TABLE ONLY public.paquet_videojocs
    ADD CONSTRAINT nom FOREIGN KEY (nom) REFERENCES public.element_compra(nom);
 >   ALTER TABLE ONLY public.paquet_videojocs DROP CONSTRAINT nom;
       public          postgres    false    217    218    4729            �           2606    16496    conte paquet    FK CONSTRAINT     v   ALTER TABLE ONLY public.conte
    ADD CONSTRAINT paquet FOREIGN KEY (paquet) REFERENCES public.paquet_videojocs(nom);
 6   ALTER TABLE ONLY public.conte DROP CONSTRAINT paquet;
       public          postgres    false    220    218    4732            �           2606    16483    compra usuari    FK CONSTRAINT     �   ALTER TABLE ONLY public.compra
    ADD CONSTRAINT usuari FOREIGN KEY (usuari) REFERENCES public.usuari(sobrenom) ON DELETE CASCADE;
 7   ALTER TABLE ONLY public.compra DROP CONSTRAINT usuari;
       public          postgres    false    215    216    4721            �           2606    16502    conte videojoc    FK CONSTRAINT     r   ALTER TABLE ONLY public.conte
    ADD CONSTRAINT videojoc FOREIGN KEY (videojoc) REFERENCES public.videojoc(nom);
 8   ALTER TABLE ONLY public.conte DROP CONSTRAINT videojoc;
       public          postgres    false    4734    220    219                  x������ � �      #      x������ � �             x������ � �      $      x������ � �      !      x������ � �            x������ � �      "      x������ � �     